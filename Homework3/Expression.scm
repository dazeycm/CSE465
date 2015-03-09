(define (randop)
  (define x (random 3))
  (cond
   ((= x 0) '+)
   ((= x 1) '*)
   ((= x 2) '-))
)

(define (createTree height)
  (cond
    ((= height 0) (list (randop) (random 10) (random 10)))
    ((list (randop) (createTree (- height 1)) (createTree(- height 1))))
  )
)

(define (testExpTree lst)
    (cond
        ((= (car lst) 0) lst)
        ((< (eval (createTree 3) user-initial-environment) (- 25)) (testExpTree(list (- (car lst) 1) (+ 1 (cadr lst)) (caddr lst) (cadddr lst))))
        ((> (eval (createTree 3) user-initial-environment) 25) (testExpTree(list (- (car lst) 1) (cadr lst) (caddr lst) (+ 1 (cadddr lst)))))
        (ELSE (testExpTree(list (- (car lst) 1) (cadr lst) (+ 1 (caddr lst)) (cadddr lst))))
     )
)

(define (findstats trials)
    (define lst (testExpTree (list trials 0 0 0)))
    (display "Number less than -25: ")
    (display (cadr lst))
    (NEWLINE)
    (display "Number between -25 and 25: ")
    (display (caddr lst))
    (NEWLINE)
    (display "Number greather than 25: ")
    (display (cadddr lst))
)

         

       