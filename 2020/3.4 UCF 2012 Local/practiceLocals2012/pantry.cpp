#include <stdio.h>
#include <string.h>

char canLabel[64][64][64];
int labelHeight[64][64];
int canWidth[64][64];
int stackHeight[64];
int stackCount;
char outputText[128][64];

void printCanTop(int i, int j, int width)
{
   int n;

   for (n = 0; n < width; n++)
      outputText[i][j+n] = '#';
}

void printCanSides(int i, int j, int width)
{
   int n;

   outputText[i][j] = '#';

   for (n = 1; n < width-2; n++)
      outputText[i][j+n] = ' ';

   outputText[i][j+width-1] = '#';
}

int renderOutput()
{
   int canStart[64][64];
   int i, j, k;
   int maxHeight;
   int lineCount;
   int offset;
   int labelTop;
   char label[64];
   char *line;
   int labelLine, labelCol;

   // Figure out the starting position of each can in the stack
   memset(canStart, 0, sizeof(canStart));
   maxHeight = stackHeight[0];
   for (i = 1; i < stackCount; i++)
   {
      // Find the position of the bottom can in this stack
      canStart[i][0] = canStart[i-1][0]+canWidth[i-1][0]+1;

      // While we're at it, find the maximum stack height
      if (stackHeight[i] > maxHeight)
         maxHeight = stackHeight[i];
   }

   // Find the remaining can positions in each stack
   for (i = 0; i < stackCount; i++)
   {
      for (j = 1; j < stackHeight[i]; j++)
      {
         // The offset for each can (relative to the can below it) is
         // simply half the difference in the two cans' widths (this
         // honors the left-favoring rule for centering the cans)
         offset = (canWidth[i][j-1] - canWidth[i][j]) / 2;
         canStart[i][j] = canStart[i][j-1] + offset;
      }
   }

   // The final output line count is simply the maximum stack height times
   // the can height (8)
   lineCount = maxHeight*8;

   // Write the can stacks to the output buffer
   for (i = 0; i < stackCount; i++)
   {
      for (j = 0; j < stackHeight[i]; j++)
      {
          // Write the outline of the can
          printCanTop(j*8, canStart[i][j], canWidth[i][j]);
          printCanSides(j*8+1, canStart[i][j], canWidth[i][j]);
          printCanSides(j*8+2, canStart[i][j], canWidth[i][j]);
          printCanSides(j*8+3, canStart[i][j], canWidth[i][j]);
          printCanSides(j*8+4, canStart[i][j], canWidth[i][j]);
          printCanSides(j*8+5, canStart[i][j], canWidth[i][j]);
          printCanSides(j*8+6, canStart[i][j], canWidth[i][j]);
          printCanTop(j*8+7, canStart[i][j], canWidth[i][j]);

          // Figure out the line where we should start writing the label
          labelTop = j*8 + 3 + labelHeight[i][j]/2;

          // Add the remainder of half the label height to honor the
          // "favor the top half of the can" rule
          labelTop += labelHeight[i][j] % 2;

          // Prepare to write the can label
          labelLine = labelTop;
          strcpy(label, canLabel[i][j]);
          line = strtok(label, "#\n");

          // Write the can label, line by line
          while (line != NULL)
          {
             // Figure out the column to start writing the label
             offset = (canWidth[i][j] - strlen(line))/2;
             labelCol = canStart[i][j] + offset;

             // Write the label at the line and column computed
             for (k = 0; k < strlen(line); k++)
                outputText[labelLine][labelCol+k] = line[k];

             // Move down one line
             labelLine--;

             // Get the next line
             line = strtok(NULL, "#\n");
          }
      }
   }

   

   return lineCount;
}

void placeCan(char *label)
{
   char temp[128];
   char *line;
   int lineCount;
   int width;
   int i;

   // Break up the can's label into lines, and use the longest line as
   // the can's width (count the label's lines as we go)
   sprintf(temp, "%s", label);
   width = 0;
   lineCount = 0;
   line = strtok(temp, "#");
   while (line != NULL)
   {
      // Increment the line count
      lineCount++;

      // Check the width and update the max width if necessary
      if (strlen(line) > width)
         width = strlen(line);

      // Try to get another line
      line = strtok(NULL, "#");
   }

   // Add two to the width to account for the sides of the can
   width += 2;

   // Now, find can's place in the stack
   i = 0;
   while ((i < stackCount) && (canWidth[i][stackHeight[i]-1] <= width))
      i++;

   // See if we should add to a stack or start a new stack
   if (i >= stackCount)
   {
      // Create a new stack with this can on the bottom
      strcpy(canLabel[i][0], label);
      labelHeight[i][0] = lineCount;
      canWidth[i][0] = width;
      stackHeight[i] = 1;

      // Increment the stack count
      stackCount++;
   }
   else
   {
      // Add the can to the first stack that fit
      strcpy(canLabel[i][stackHeight[i]], label);
      labelHeight[i][stackHeight[i]] = lineCount;
      canWidth[i][stackHeight[i]] = width;
      stackHeight[i]++;
   }
}


int main(void)
{
   FILE *fp;
   char line[128];
   char *nl;
   int numSets;
   int numCans;
   int i, j;
   int lineCount;
   
   // Open the input file
   fp = fopen("pantry.in", "r");

   // Get the number of data sets
   fscanf(fp, "%d\n", &numSets);

   // Process each data set
   for (i = 0; i < numSets; i++)
   {
       // Initialize the can stack data and output text buffer
       memset(canLabel, 0, sizeof(canLabel));
       memset(canWidth, 0, sizeof(canWidth));
       memset(stackHeight, 0, sizeof(stackHeight));
       stackCount = 0;

       // Initialize the output text buffer to all spaces, and null-terminate
       // each line
       memset(outputText, 0x20, sizeof(outputText));
       for (j = 0; j < 128; j++)
          outputText[j][63] = 0;

       // Get the number of cans
       fscanf(fp, "%d\n", &numCans);

       // Process each can label
       for (j = 0; j < numCans; j++)
       {
           // Read the next can label (strip off the newline character)
           fgets(line, sizeof(line), fp);
           nl = strchr(line, '\n');
           if (nl != NULL)
              *nl = 0;

           // Place the can in the stack
           placeCan(line);
       }

       // Render the can stacks into the ouput buffer
       lineCount = renderOutput();

       // Finally, print the output
       printf("Can Stack #%d:\n", i+1);
       printf("         1         2         3         4         5         6\n");
       printf("123456789012345678901234567890123456789012345678901234567890\n");
       for (j = lineCount-1; j >= 0; j--)
           printf("%s\n", outputText[j]);
       printf("\n");
   }
}
