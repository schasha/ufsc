board :: String -> [String]
board file_string = [snd x | x <- zip [0..] l, fst x `mod` 2 == 1]
      where l = [[snd y | y <- zip [0..] line, fst y `mod` 2 == 1] | line <- lines file_string]

areas :: String -> [String]
areas file_string = spread 2 2 1 b_areas file_string
      where b_areas = [[0 | x <- [2, 4..(length $ lines file_string)]] | x <- [2, 4..(length $ lines file_string)]]

spread :: Int -> Int -> Int -> [String] -> String -> [String]
spread x y a arr file_string = 

main = do
    file_string <- readFile "./board2.txt"
    let b = board file_string
    putStr (unlines $ map show [[0 | x <- [2, 4..(length $ lines file_string)]] | x <- [2, 4..(length $ lines file_string)]])
    putStr (unlines $ map show b)
