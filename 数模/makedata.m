
[num]=xlsread('D:\GitHub\acm-codes\ÊıÄ£\data.xls');

input = num(:,5:14);
output = num(:,3);

input = flipud(input);
output = flipud(output);