(require :asdf)
(deftype area () 'integer)
(deftype guess () 'integer)
(defstruct posi ;tion
  x y area guess)

(defun set-guess (pos g)
  (setf (posi-guess pos) g)
  pos
)

;; utils
(defun split-string-by-newline (s)
  (let ((result (uiop:split-string s :separator '(#\Newline))))
    (if (and result (string= (car (last result)) ""))
        (butlast result)
        result)
  )
)

(defun concatenate-strings (string-list)
  (reduce #'concatenate string-list)
)

(defun string-to-list (s)
  (loop for char across s collect char)
)

;; criacao do tabuleiro
; cria um tabuleiro de tamanho i x i
(defun create-board (i)
  (let ((board '()))
    (dotimes (x i)
      (dotimes (y i)
        (push (make-posi :x x :y y :area -1 :guess -1) board)))
    board
  )
)

; atualiza o tabuleiro com os numeros da entrada, considerando as barreiras
(defun set-input-guess (file-string board)
  (let* ((lines (split-string-by-newline file-string))
         (lines_list (mapcar #'string-to-list lines))
         (guesses '())
         (len (length lines_list))
         )
         (loop for i from 0 below len do
            (loop for j from 0 below len do
                (when (and (oddp i) (oddp j))
                    (if (null (digit-char-p (nth j (nth i lines_list))))
                        (push 0 guesses)
                        (push (digit-char-p (nth j (nth i lines_list))) guesses)))))
         (mapcar #'set-guess board (reverse guesses))
  )
)

; computa a area de todas as posices
(defun set-areas (file-string board)
  (loop for i from 0 below (length board) do
        (spread file-string board i i))
)

; funcao auxiliar para computador a area, preenche com uma determinada area
; enquanto a posicao for vizinha
(defun spread (file-string board pos area)
  (if (= (posi-area (nth pos board)) -1)
    (progn
      (setf (posi-area (nth pos board)) area)
      (loop for neighbour in (get-neighbours-input file-string board (nth pos board)) do
             (spread file-string board neighbour area))))
)

(defun get-barriers-index (length x y)
  (let ((list-index (+ (* x length) y)))
        (loop for m in (list (1- list-index) (1+ list-index) (- list-index length) (+ list-index length))
              collect (if (<= 0 m (1- (* length length))) m -1)))
)

(defun get-neighbours-index (length x y)
  (let ((list-index (+ (* x length) y)))
       (loop for m in (list (- list-index 2) (+ list-index 2) (- list-index (* 2 length)) (+ list-index (* 2 length)))
             collect (if (<= 0 m (1- (* length length))) m -1)))
)

(defun index-conversion (m len-file board-size)
  (+ (* (truncate (1- (truncate (1- m) len-file)) 2) board-size)
    (truncate (1- (mod m len-file)) 2))
)

(defun filter-indexes (barriers neighbours string len-file)
  (let ((result '()))
        (loop for (barrier . neighbour) in (mapcar #'cons barriers neighbours) do
        (when (and (not (= barrier -1))
                   (char= (char string barrier) #\Space)
                   (not (= neighbour -1)))
              (push neighbour result)))
    (reverse result))
)

; pega o indice dos vizinhos considerando o tipo de input apresentado
(defun get-neighbours-input (file-string board pos)
  (let* ((p (posi-x pos))
         (q (posi-y pos))
         (x (1+ (* 2 p)))
         (y (1+ (* 2 q)))
         (str (remove #\Newline file-string))
         (len-file (length (split-string-by-newline file-string)))
         (board-size (isqrt (length board)))
         (barriers (get-barriers-index len-file x y))
         (neighbours (get-neighbours-index len-file x y))
         (indexes (filter-indexes barriers neighbours str len-file))
         )
         (mapcar #'(lambda (m) (index-conversion m len-file board-size)) indexes)
  )
)

; resolucao
; pega as posicoes de uma determinada area
(defun get-area-positions (board area)
  (loop for x in board
        for index from 0
        when (= (posi-area x) area)
        collect index)
)

(defun check-up (board pos guess size)
  (cond ((< (- pos size) 0) t)
        ((= (posi-area (nth pos board)) (posi-area (nth (- pos size) board)))
            (< guess (posi-guess (nth (- pos size) board))))
        (t (/= guess (posi-guess (nth (- pos size) board)))))
)

(defun check-down (board pos guess size len)
  (cond ((>= (+ pos size) len) t)
        ((= (posi-area (nth pos board)) (posi-area (nth (+ pos size) board)))
            (> guess (posi-guess (nth (+ pos size) board))))
        (t (/= guess (posi-guess (nth (+ pos size) board)))))
)

(defun check-left (board pos guess)
  (cond ((< (- pos 1) 0) t)
        (t (/= guess (posi-guess (nth (- pos 1) board)))))
)

(defun check-right (board pos guess len)
  (cond ((>= (+ pos 1) len) t)
        (t (/= guess (posi-guess (nth (+ pos 1) board)))))
)

; verifica se um chute eh valido para determinada posicao no tabuleiro
(defun check-guess (board pos guess)
  (let* ((area (posi-area (nth pos board)))
         (area-positions (get-area-positions board area))
         (area-guesses (mapcar #'(lambda (p) (posi-guess (nth p board))) area-positions))
         (size-area (length area-positions))
         (size (isqrt (length board)))
         (len (length board)))
    (and (not (member guess area-guesses))
         (<= guess size-area)
         (check-up board pos guess size)
         (check-down board pos guess size len)
         (check-left board pos guess)
         (check-right board pos guess len))
  )
)

; cria um novo tabuleiro com o novo chute, para continaur o backtracking
(defun set-guess-board (board pos guess)
  (let ((copy (copy-list board)))
        (setf (posi-area (nth pos copy)) guess)
        copy)
)

; itera sobre o tabuleiro tentando colocar um chute, se o chute for valido,
; tenta resolver o novo tabuleiro ate que, ou ele nao tenha uma solucao, ou
; ele encontre a solucao do problema
(defun solve-aux (board pos guess)
  (let (new-solved-board (solve (set-guess-board board pos guess)))
  (cond ((>= pos (length board)) board)
        ((/= (posi-guess (nth pos board)) 0)
             (solve-aux board (1+ pos) 1))
        ((= guess 10) nil)
        ((or (not (check-guess board pos guess))
             (null new-solved-board))
             (solve-aux board pos (1+ guess)))
        (t new-solved-board))
  )
)

(defun solve (board)
  (solve-aux board 0 1)
)

(defun main ()
  (let* ((args (uiop:command-line-arguments))
         (file-path (first args))
         (file-string (uiop:read-file-string file-path))

         ; cria o tabuleiro
         (board-size (floor (length (split-string-by-newline file-string)) 2))
         (b1 (create-board board-size))
         (b2 (reverse b1)))
         (set-input-guess file-string b2)
         (set-areas file-string b2)

         ; resolucao
         (print(solve b2))
         (terpri)
  )
)

(main)
