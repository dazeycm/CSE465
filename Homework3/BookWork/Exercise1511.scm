;Write a Scheme function that takes two atoms and a list as parameters
;and returns a list identical to the parameter list except all occurrences of
;the first given atom in the list are replaced with the second given atom,
;no matter how deeply the first atom is nested.
    
(define (swap x y lst)
    (cond
        ((null? lst) '() )
        ((list? (car lst)) (cons (swap x y (car lst)) (swap x y (cdr lst))))
        ((= (car lst) x) (cons y (swap x y (cdr lst))))
        (else (cons (car lst) (swap x y (cdr lst))))
    )
)