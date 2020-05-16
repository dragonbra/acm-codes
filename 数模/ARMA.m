close all
clear all
load Data_EquityIdx   %纳斯达克综合指数
len = 120;
% Y = DataTable.NASDAQ(1:len)
load data input;
Y = input(:,10:10);
data = Y;
plot(Y)

y_h_adf = adftest(Y)
y_h_kpss = kpsstest(Y)

Yd1 = diff(Y);
yd1_h_adf = adftest(Yd1)
yd1_h_kpss = kpsstest(Yd1)

% ACF和PACF法，确定阶数
% figure
% autocorr(aimY)
% figure
% parcorr(aimY)

% 通过AIC，BIC等准则暴力选定阶数
% max_ar = 3;
% max_ma = 3;
% [AR_Order,MA_Order] = ARMA_Order_Select(Y,max_ar,max_ma,1);   

AR_Order =    1
MA_Order =    3

Mdl = arima(AR_Order, 1, MA_Order);  %第二个变量值为1，即一阶差分
EstMdl = estimate(Mdl,data);
[res,~,logL] = infer(EstMdl,data);   %res即残差

stdr = res/sqrt(EstMdl.Variance);
figure('Name','残差检验')
subplot(2,3,1)
plot(stdr)
title('Standardized Residuals')
subplot(2,3,2)
histogram(stdr,10)
title('Standardized Residuals')
subplot(2,3,3)
autocorr(stdr)
subplot(2,3,4)
parcorr(stdr)
subplot(2,3,5)
qqplot(stdr)

% Durbin-Watson 统计是计量经济学分析中最常用的自相关度量
diffRes0 = diff(res);  
SSE0 = res'*res;
DW0 = (diffRes0'*diffRes0)/SSE0 % Durbin-Watson statistic，该值接近2，则可以认为序列不存在一阶相关性。

% 5.预测
step = 300; %预测步数为300
[forData,YMSE] = forecast(EstMdl,step,'Y0',data);   %matlab2018及以下版本写为Predict_Y(i+1) = forecast(EstMdl,1,'Y0',Y(1:i)); 
lower = forData - 1.96*sqrt(YMSE); %95置信区间下限
upper = forData + 1.96*sqrt(YMSE); %95置信区间上限

figure()
plot(data,'Color',[.7,.7,.7]);
hold on
h1 = plot(length(data):length(data)+step,[data(end);lower],'r:','LineWidth',2);
plot(length(data):length(data)+step,[data(end);upper],'r:','LineWidth',2)
h2 = plot(length(data):length(data)+step,[data(end);forData],'k','LineWidth',2);
legend([h1 h2],'95% 置信区间','预测值',...
	     'Location','NorthWest')
title('煤炭产量 Forecast')
hold off

forData = normrnd(forData, sqrt(YMSE) );
figure()
plot(forData)