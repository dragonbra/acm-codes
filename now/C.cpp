if (blank) reject; // restart 1
else if (a) 
    delete a and move right
    move right over all a's;
    if (b) 
        delete b and move left
    else if (blank) accept;
else if (b)
    delete b and move right
    move right over all b's;
    if (a)
        delete a and move left;
    else if (blank) reject;

if (blank) reject; // restart2
else if (a) accept;
else if (b) reject;