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

;(define (testtestest numTrees lessthan between greaterthan)
 ;   (cond
  ;      ((= numTrees 0) (display "Goodbye!"))
    ;    (else(let()(begin 
     ;           (define y (createTree 2))
      ;          (cond
       ;             ((< (eval y user-initial-environment) (- 25)) (testtestest (- numTrees 1) (+ 1 lessthan) between greaterthan))
        ;            ((> (eval y user-initial-environment) 25) (testtestest (- numTrees 1) lessthan between (+ 1 greaterthan)))
         ;           (else (testtestest (- numTrees 1) lessthan (+ 1 between) greaterthan))
          ;       )
           ;     )
           ; )
;        )
 ;    )
  ;)

(define (testExpTree lst)
    (cond
        ((= (car lst) 0) lst)
        ((< (eval (createTree 3) user-initial-environment) (- 25)) (testExpTree(list (- (car lst) 1) (+ 1 (cadr lst)) (caddr lst) (cadddr lst))))
        ((> (eval (createTree 3) user-initial-environment) 25) (testExpTree(list (- (car lst) 1) (cadr lst) (caddr lst) (+ 1 (cadddr lst)))))
        (ELSE (testExpTree(list (- (car lst) 1) (cadr lst) (+ 1 (caddr lst)) (cadddr lst))))
     )
)
        



(define (findstats trials)
    (define x (testExpTree (list trials 0 0 0)))
    (display x)
)


;(display "Number less than -25:")
       ;         (display lessthan)
        ;        (display "Number between -25 and 25:")
        ;        (display between)
         ;       (display "Number greather than 25:")
         ;       (display greaterthan)
         
         
;(define (testExpTree lst)
  ;  (cond
   ;     ((= (car lst) 0) lst)
    ;    ((< (eval (createTree 3) user-initial-environment) (- 25)) (testExpTree(list (- (car lst) 1) (+ 1 (cadr lst)) (caddr lst) (cdddr lst))))
     ;   ((> (eval (createTree 3) user-initial-environment) 25) (testExpTree(list (- (car lst) 1) (cadr lst) (caddr lst) (+ 1 (cdddr lst)))))
    ;    (else (testExpTree((list (- (car lst) 1) (caar list) (+ 1 (caaar lst)) (caaaar lst)))))
    ; )
;)
       