comprimento :: [a] -> Int
comprimento [] = 0
comprimento (_:b) = 1 + comprimento b

soma :: [Int] -> Int
soma [] = 0
soma (a:b) = a + soma b

media :: [Int] -> Float
media [] = 0
media lista = fromIntegral (soma lista) / fromIntegral (comprimento lista)

main = print (media [1..10])
