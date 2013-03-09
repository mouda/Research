correlationArray = dlmread('src/result');
degree=2.5:50;
plot(degree,correlationArray);
xlabel('Distance(s)');
ylabel('Correlation Coefficient');
title('Correlation Coefficient Varying by Distance')
grid on;