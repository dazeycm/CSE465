maxnums(X, Y, X) :- X >= Y.
maxnums(X, Y, Y) :- X < Y.

sum([], 0).
sum([H|T], Sum) :- sum(T, X), Sum is H + X.

parent(mike, abigail).
parent(mike, christy).
parent(mike, mack).
male(mack).
male(mike).
female(abigail).
female(christy).
sister(X, Y) :- parent(Z, X), parent(Z, Y), female(X).

max([X], X).
max([X|T], X) :- max(T, Y), X >= Y.
max([X|T], P) :- max(T, P), P > X.

maxnum(A, B, C, X) :- max([A, B, C], X).

partitionable(L) :- append(X, Y, L), sum(X, P), sum(Y, P).
