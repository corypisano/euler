%% Problem 99 - Largest exponential
% Cory Pisano
% March 21, 2014
%
% extremely simple problem. computation is under 0.05 seconds on my
% machine. 
% all exponential pairs will maintain:
%           log(x1^y1) > log(x2^y2) if x1^y1 > x2^y2
% very easy and efficient to just use the log property: 
%           log(x^y) = y*log(x);
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

% parse text file
fid = fopen('base_exp.txt');
data = textscan(fid,'%f,%f\n');

% ( base, exp ) <->  ( data{1}(i), data{2}(i) )
% log(x^y) = y*log(x);
max = 0;
for i = 1:length(data{1})
   base = data{1}(i);
   exp  = data{2}(i);
   check = exp*log10(base);
   
   % new max found
   if check > max
       max = check;
       max_base = base;
       max_exp = exp;
       line_number = i;
   end
end
toc
fprintf('\nLine number %d:   %d^%d\n', line_number,max_base,max_exp);
