(defun power (x y)
  (if (= y 0)
        1
        (* x (power x (- y 1)))
  )
)

(write (power (read) (read)))
