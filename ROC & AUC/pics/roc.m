scores = [0.1, 0.5, 0.3, 0.8];
labels = [0, 1, 0, 1];
len = length(scores);
TPR = zeros(len, 1);
FPR = zeros(len, 1);

for i = 1:len
    th = scores(i);
    pred = scores>=th;
    TPR(i) = sum( (pred==1)&(labels==1) ) / sum(labels==1);
    FPR(i) = sum( (pred==1)&(labels==0) ) / sum(labels==0);
end
figure();
hold on;
[~,I] = sort(FPR);
FPR = FPR(I);
TPR = TPR(I);
plot(FPR,TPR,'linewidth',2);
plot([0,1],[0,1],'r','linewidth',2)
legend('classifier','random guess');
grid on;
% axis tight;
% axis equal;
axis([0,1,0,1]);
xlabel('FPR');
ylabel('TPR');
title('ROC Curve')

% axis([-0.1,1.1,-0.1,1.1]);