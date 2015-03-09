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