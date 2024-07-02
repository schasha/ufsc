import Data.Char
import System.Environment (getArgs)

type Area = Int
type Guess = Int
data Position = Position Int Int Area Guess deriving (Show, Eq)
type Board = [Position]

getArea :: Position -> Int
getArea (Position _ _ a _) = a

getGuess :: Position -> Int
getGuess (Position _ _ _ g) = g

setArea :: Position -> Int -> Position
setArea (Position x y _ g) a = Position x y a g

setGuess :: Position -> Int -> Position
setGuess (Position x y a _) = Position x y a

--- criacao do tabuleiro
-- cria um tabuleiro de tamanho i x i
createBoard :: Int -> Board
createBoard i = [Position x y (-1) (-1) | x <- [0..(i-1)], y <- [0..(i-1)]]

-- atualiza o tabuleiro com os numeros da entrada, considerando quais posicoes
-- sao os numeros e quais sao as barreiras
setInputGuess :: String -> Board -> Board
setInputGuess file_string board = zipWith setGuess board guesses
              where guesses = concat m
                    m = [snd x | x <- zip [0..] l, fst x `mod` 2 == 1]
                    l = [[if isDigit (snd y::Char) then digitToInt $ snd y else 0 | 
                          y <- zip [0..] line, fst y `mod` 2 == 1] | 
                          line <- lines file_string]

-- funcao que computa a area de todas as posicoes
setAreas :: String -> Board -> Board
setAreas file_string board = foldl (\board pos -> spread file_string board pos pos) board [0..length board-1]

-- funcao auxiliar para computar cada aerea, basicamente um algoritmo de flood fill,
-- enquanto for vizinho, preenche com a mesma area
spread :: String -> Board -> Int -> Int -> Board
spread file_string board pos area = 
    if getArea (board!!pos) /= -1 then
        board
    else
        -- fold sobre todos os vizinhos 
        foldl (\board pos -> spread file_string board pos area) new_board neighbours

        where neighbours = getNeighboursInput file_string board (board!!pos)

              -- novo tabuleiro com a area de pos trocada
              new_board = replacePositionArea board pos area 0

              -- funcao auxilar
              replacePositionArea [] pos area count = []
              replacePositionArea (cur@(Position x y a g):xs) pos area count
                              | pos == count = Position x y area (-1):replacePositionArea xs pos area (count+1)
                              | otherwise    = cur:replacePositionArea xs pos area (count+1)

-- funcao auxiliar que pega os indices dos vizinhos, considerando as barreiras do input
getNeighboursInput :: String -> Board -> Position -> [Int]
getNeighboursInput file_string board (Position p q _ _) = [indexConversion m | m <- indexes] 
              where x = 2*p + 1 -- conversao de indices de uma "matriz" tabuleiro para uma "matriz" input
                    y = 2*q + 1

                    string = concat $ lines file_string
                    len_file = length $ lines file_string
                    board_size = floor $ sqrt $ fromIntegral $ length board

                    -- filtra quais vizinhos fazem parte da mesma area
                    indexes = [snd m | m <- zip (getBarriersIndex len_file x y) (getNeighboursIndex len_file x y), fst m /= -1, string!!fst m == ' ', snd m /= -1]

                    -- conversao entre indice do input para indice do tabuleiro
                    indexConversion m = ((((m-1) `div` len_file)-1) `div` 2) * board_size + ((m `mod` len_file)-1) `div `2

                    -- indice de cada barreira
                    getBarriersIndex length x y = [if m `elem` [0..length*length-1] then m else -1 | 
                                                  m <- [list_index - 1, list_index + 1, list_index - length, list_index + length]]
                                    where list_index = x*length + y
                    -- indice de cada casa vizinha na string de input
                    getNeighboursIndex length x y = [if m `elem` [0..length*length-1] then m else -1| 
                                                     m <- [list_index - 2, list_index + 2, list_index - 2*length, list_index + 2*length]]
                                       where list_index = x*length + y

--- resolucao
-- cria um novo tabuleiro com um novo chute
setNewGuess :: Board -> Int -> Guess -> Int -> Board
setNewGuess [] pos guess count = []
setNewGuess (cur@(Position x y a _):xs) pos guess count
            | pos == count = Position x y a guess:setNewGuess xs pos guess (count+1)
            | otherwise    = cur:setNewGuess xs pos guess (count+1)

-- pega todas as posicoes de uma determinada area
getAreaPositions :: Board -> Int -> [Int]
getAreaPositions board area = [getIndex x | x <- board, getArea x == area]
                 where getIndex (Position x y _ _) = x * floor (sqrt $ fromIntegral $ length board) + y
                    
-- verifica se um chute pode estar em uma posicao de acordo com as regras do jogo
checkGuess :: Board -> Int -> Int -> Bool
checkGuess board pos guess = 
    -- unico na area
    notElem guess area &&
    guess <= size_area &&
    -- ortogonais diferentes
    checkUp board pos guess &&
    checkDown board pos guess &&
    checkLeft board pos guess &&
    checkRight board pos guess
        -- lista de numeros na area
        where area = [getGuess (board!!x) | x <- getAreaPositions board (getArea (board!!pos))]
              size_area = length area
              size = floor $ sqrt $ fromIntegral $ length board
              len = length board
              checkUp board pos guess
                    |(pos-size) < 0 = True
                    |getArea (board!!pos) == getArea (board!!(pos-size)) = guess < getGuess (board!!(pos-size))
                    |otherwise = guess /= getGuess (board!!(pos-size))
              checkDown board pos guess
                    |(pos+size) >= len = True
                    |getArea (board!!pos) == getArea (board!!(pos+size)) = guess > getGuess (board!!(pos+size))
                    |otherwise = guess /= getGuess (board!!(pos+size))
              checkLeft board pos guess
                    |(pos-1) < 0 = True
                    |otherwise = guess /= getGuess (board!!(pos-1))
              checkRight board pos guess
                    |(pos+1) >= len = True
                    |otherwise = guess /= getGuess (board!!(pos+1))

-- itera sobre o tabuleiro tentando colocar um chute, se o chute for valido,
-- tenta resolver o novo tabuleiro ate que, ou ele nao tenha uma solucao, ou
-- ele encontre a solucao do problema
solve :: Board -> Maybe Board
solve board = solve' board 0 1
    where solve' :: Board -> Int -> Int -> Maybe Board 
          solve' board pos guess
            |pos >= length board = Just board
            |getGuess (board!!pos) /= 0 = solve' board (pos+1) 1
            |guess == 10 = Nothing -- maior regiao possivel 
            |otherwise = if (not $ checkGuess board pos guess) || new_solved_board == Nothing then
                            solve' board pos (guess+1)
                         else
                            new_solved_board
                         where new_solved_board = solve $ setNewGuess board pos guess 0

main = do
    -- argumentos
    args <- getArgs
    let file_path = case args of (arg:_) -> arg
    file_string <- readFile file_path

    -- contrucao do tabuleiro
    let board_size = div (length $ lines file_string) 2
    let b1 = createBoard board_size
    let b2 = setAreas file_string b1
    let b3 = setInputGuess file_string b2

    -- print tabuleiro e areas
    --putStr (unlines $ map show (chunksOf board_size (map getGuess b3)))
    --putStr (unlines $ map show (chunksOf board_size (map getArea b3)))

    -- resolucao
    let result = solve b3
    case result of
        Nothing -> print "haha"
        Just board -> putStr (unlines $ map show (chunksOf board_size (map getGuess board)))


-- from Data.List.Split
build :: ((a -> [a] -> [a]) -> [a] -> [a]) -> [a]
build g = g (:) []

chunksOf :: Int -> [e] -> [[e]]
chunksOf i ls = map (take i) (build (splitter ls))
    where
        splitter :: [e] -> ([e] -> a -> a) -> a -> a
        splitter [] _ n = n
        splitter l c n = l `c` splitter (drop i l) c n

