(defun abss (x)
    (if (>= x 0)
        x
        (- 0 x)
    )
)

(write (abss (read)))
