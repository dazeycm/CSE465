;Write a Scheme function that computes the real roots of a given quadratic
;equation. If the roots are complex, the function must display a
;message indicating that. This function must use an IF function. The
;three parameters to the function are the three coefficients of the quadratic
;equation.

(define (quadratic a b c)
    (define discriminate (- (* b b)
                            (* 4 a c)))
    (if (< discriminate 0)
        (display "Roots are complex!")
        ( begin
            (display "Root 1: ")
            (display (/ (+ (- b) (sqrt discriminate))
               (* 2 a)))
            (newline)
            (display "Root 2: ")
            (display (/ (- (- b) (sqrt discriminate))
               (* 2 a)))
        )
    )
)