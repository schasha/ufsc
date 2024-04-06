maior :: [Int] -> Int
maior [] = 0
maior [a] = a
maior (a:b) = 
    if a > maior b then
        a
    else
        maior b

menor :: [Int] -> Int
menor [] = 0
menor [a] = a
menor (a:b) = 
    if a < menor b then
        a
    else
        menor b

diferencaMaiorMenor :: [Int] -> Int
diferencaMaiorMenor [] = 0
diferencaMaiorMenor lista = maior lista - menor lista

main = print (diferencaMaiorMenor [1..20])
