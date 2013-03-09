clear;
close all;
R=300; % Radius(m)
N=100; % Number of machine

rPosTheta=rand(1,N);  % Random of position
rPosRadius=rand(1,N); % Random of position
rDirTheta=rand(1,N)*2*pi;  % Random of direction
x=rPosRadius*R.*cos(rPosTheta*2*pi);
y=rPosRadius*R.*sin(rPosTheta*2*pi);

xEnd=cos(rDirTheta)*0.0001;
yEnd=sin(rDirTheta)*0.0001;

outputData=[x' y' rDirTheta'];
% The first column is the x position
% The second column is the y position
% The third column is the diraction
dlmwrite('map.out',outputData,'delimiter',' ');
%scatter(x,y);
%hold;
%scatter(xEnd,yEnd);
%annotation('arrow',[x(1) y(1)],[xEnd(1) yEnd(1)])
%annotation('arrow',[.39 .39],[.11 .39])
%arrowline([.39 .39],[.11 .39])
%h = quiver(x,y,xEnd,yEnd);


