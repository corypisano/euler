%% Problem 49 - Prime permutations
% Cory Pisano
% March 21, 2014
%
% computation is under 1 second on my machine. Can be optimized further by
% realizing the desired sequence has primes with a difference of 3300, just
% as the first sequence does. did not know this before computing. also
% could loop through only unique permutations of the primes from 1000-9999
% instead of all primes from 1000-9999. 
%
%%
% Prime permutations Problem 49 The arithmetic sequence, 1487, 4817, 8147,
% in which each of the terms increases by 3330, is unusual in two ways: (i)
% each of the three terms are prime, and, (ii) each of the 4-digit numbers
% are permutations of one another.
% 
% There are no arithmetic sequences made up of three 1-, 2-, or 3-digit
% primes, exhibiting this property, but there is one other 4-digit
% increasing sequence.
% 
% What 12-digit number do you form by concatenating the three terms in this
% sequence?
%
%%
clear all; close all; clc
tic
% get 4 digit primes
primeNums = primes(9999);
primeNums = primeNums(primeNums>1000);

count = 0;      % count of desired prime sequences
result{1} = ''; % cell array of desired sequences
converter = [1000 100 10 1]; % to convert from digit array to number

for x = primeNums
    % split x into digits, get all permutations of digits
    digits = num2str(x);
    digits = [  str2double(digits(1)) ...
                str2double(digits(2)) ...
                str2double(digits(3)) ...
                str2double(digits(4))   ];
    all_perms = unique(perms(digits), 'rows');
    
    % build sequence of 4 digit prime permutations of x
    seq = x;
    for i = 1:length(all_perms)
       xperm = sum(all_perms(i,:).*converter);
  
       if (xperm < 1000) || (xperm == x) 
           continue;
       end
       
       if (isprime(xperm))
           seq = [seq xperm]; 
       end
    end
    
    % need at least 3 primes in the sequence
    if (length(seq) < 3)
       	continue;
    end
    
    % sort sequence, check if any 3 of the primes have the same
    % difference. add to results if unique solution.
    seq = sort(seq);
    for i = 1:length(seq)
        test2 = seq - seq(i);
        for i2 = 1:length(seq)
           if  (any( abs(test2./test2(i2)- 2) < .001)) % (float==2)
               if (ismember(result,num2str(seq)) == 0)
                   count = count + 1;
                   result{count} = num2str(seq);
               end
           end
        end
    end
    
    % second sequence found!
    if count > 1 
        break;
    end
end
toc
% print results
fprintf('First sequence: %s\n',result{1})
fprintf('Second sequence: %s\n',result{2})
