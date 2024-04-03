primeiros :: Int -> [t] -> [t]
primeiros n [] = []
primeiros n (a:b) = 
    if n-1 > 0 then
        a : primeiros (n-1) b
    else
        [a]

main = print (primeiros 5 [1..10])

