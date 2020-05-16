clear;

[num]=xlsread('D:\GitHub\acm-codes\ÊýÄ£\data.xls');

x0 = num(1:51,3)';
x = num(1:51,4:9)';

x0 = x0 / sum(x0);
for i = 1:6
    x(i,:) = x(i,:) / sum( (x(i,:)) );
end


% x0 = normalize(x0);
% for i = 1:6
%     x(i,:) = normalize(x(i,:));
% end


M = 0;m = 1;

for i = 1:6
    for j = 1:51
        M = max(M, abs(x0(j) - x(i,j)));
        m = min(m, abs(x0(j) - x(i,j)));
    end
end

r = zeros(6,1); ep = 1/2;
for i = 1:6
    for j = 1:51
        r(i) = r(i) + (m + ep * M) / ( abs((x0(j) - x(i,j))) + ep * M );
    end
end
r = r / sum(r);
