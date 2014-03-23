%% Problem 53 - Combinatoric selections
% Cory Pisano
% March 21, 2014
%
% extremely simple problem. computation is under 1 second on my
% machine. just brute force 
%       nchoosek(n,k),  1<n<=100, 1<k<n
%%
% Comparing two numbers written in index form like 211 and 37 is not
% difficult, as any calculator would confirm that 211 = 2048 < 37 = 2187.
% 
% However, confirming that 632382518061 > 519432525806 would be much more
% difficult, as both numbers contain over three million digits.
% 
% Using base_exp.txt (right click and 'Save Link/Target As...'), a 22K text
% file containing one thousand lines with a base/exponent pair on each
% line, determine which line number has the greatest numerical value.
% 
% NOTE: The first two lines in the file represent the numbers in the
% example given above.

%%
clear all; close all; clc
tic
warning('off','all'); % suppress warnings (exactness in nchoosek)
count = 0;
for n = 1:100
    for k = 1:n
        if nchoosek(n,k)>1000000
            count = count+1;
        end
    end
end
toc

count