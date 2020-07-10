# Alice is learning mathematical functions. In his assignment, 
# teacher has asked him to evaluate h(x)= f(x)+g(x) where
# f(x)=3x2-x+10 and
# g(x)=4x3+2x2-5x+4.
# As he is weak in mathematics, help him finish this task.

# Hint: Since X is large, you need to work with Big Integers!

# Input Format
# Single line containing an integral value denoting the value of x.

# Constraints
# 0<=x<=10^50

# Output Format
# Print integral value denoting value of h(x).

# Sample Input
# 1
# Sample Output
# 17
# Explanation
# f(1)=3-1+10=12 g(1)=4+2-5+4=5 h(1)=f(1)+g(1)=12+5=17

n = int(input())
ans = (3*(n*n) - n + 10) + (4*(n*n*n) + 2*(n*n) - 5*n + 4)
print(ans)