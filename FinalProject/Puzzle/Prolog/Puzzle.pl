sum([], 0).
sum([H|T], Sum) :- sum(T, X), Sum is H + X.

partitionable(L) :- append(X, Y, L), sum(X, P), sum(Y, P), !.
isPartitionable(L) :- append(X, Y, L), partitionable(X), partitionable(Y).
