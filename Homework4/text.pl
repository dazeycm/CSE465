likes(X, chocholate).

likes(fred, chips).

likes(fred, soda).

likes(sue, chips).

likes(jane, soda).

likes(X, Y) :- friends(X, Y).

friends(fred, sue).

friends(jane, sue).

friends(sue, jane).

lw(X, [X|_]).

ok([]).

ok([H|T]) :- not(lw(H,T)), ok(T).