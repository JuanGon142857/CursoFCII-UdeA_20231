clear all
close all
% 
filename = "./Ejemplo expo.csv";
% 
M = csvread(filename);

x = -30 : 0.05 : 70;
y = 0 :  50 / size(M,2) : 50;

figure(1)
ax = gca;
imagesc(abs(M))
xlabel("posición",'FontSize',25)
ylabel("tiempo",'FontSize',25)
ax.XAxis.FontSize = 25;
ax.YAxis.FontSize = 25;
colorbar;





















% xL = -30; xR = 70;
% N = 2001;
% h = (xR - xL) / (N - 1);
% 
% beta = 0.5;
% k = 0.01;
% gamma = 2./3;
% 
% mass = zeros(1, size(M, 1));
% 
% for i = 1 : 1 : size(M, 1)
%     mass(i) = (2 * sum(abs(M(i, :)) .^ 2) - abs(M(i, 1))^2 - abs(M(i,2002))^2) * h / 2;
% end
% 
% momentum = zeros(1, size(M, 1));
% 
% for i = 1 : 1 : size(M, 1)
%     for j = 2 : 1 : N - 1
%         momentum(i) = momentum(i) - abs(imag(M(i, j)) * (real(M(i, j + 1)) - real(M(i, j - 1)))) - abs(real(M(i, j)) * (imag(M(i, j + 1)) - imag(M(i, j - 1))));
%     end
% end
% 
% energy = zeros(1, size(M, 1));
% for i = 1 : 1 : size(M, 1)
%     for j = 2 : 1 : N - 1
%         energy(i) = energy(i) + gamma * h / 4 * (abs(M(i, 1))^4 + abs(M(i, 2002))^4);
%         energy(i) = energy(i) + beta / (8. * h) * ((real(M(i, j + 1)) - real(M(i, j - 1)))^2 +(imag(M(i, j + 1)) - imag(M(i, j - 1)))^2 );
%         energy(i) = energy(i) + gamma * h / 2 * abs(M(i, j))^4;
%     end
% end
% 
% figure(2)
% plot(mass)
% ylabel("Masa")
% xlabel("Tiempo")
% 
% figure(3)
% plot(momentum)
% ylabel("Momentum")
% 
% figure(4)
% plot(energy)
% ylabel("Energia")