%% Problem 22 - Names scores
% Cory Pisano
% March 21, 2014
%
% computation is under 0.1 seconds on my machine.
%
%%
% Using names.txt, a 46K text file containing over five-thousand first
% names, begin by sorting it into alphabetical order. Then working out the
% alphabetical value for each name, multiply this value by its alphabetical
% position in the list to obtain a name score.
% 
% For example, when the list is sorted into alphabetical order, COLIN,
% which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list.
% So, COLIN would obtain a score of 938 × 53 = 49714.
% 
% What is the total of all the name scores in the file?

%%
clear all; close all; clc
tic
% parse text file (comma separated names) and remove quotations
fid = fopen('names.txt');
data = textscan(fid,'%s','Delimiter',',');
data{1} = strrep(data{1},'"','');

% sort list of names alphabetically
abc_names = sort(data{1});

%%

result = 0;   % running total of name scores in the file
for index = 1:length(abc_names)
    name = abc_names{index};       % abc_names{938} = 'COLIN'
    score = sum( name - 64);       % sum([3 15 12 9 14]) = 53
    result = result + score*index; % name score = 938*53
end
toc
disp('Total of all name scores: ')
disp(result)
