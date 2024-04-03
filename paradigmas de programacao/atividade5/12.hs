apagar :: Int -> [t] -> [t]
apagar n [] = []
apagar n (a:b) = 
    if n > 0 then
        apagar (n-1) b
    else
        a:b

main = print (apagar 5 [1..10])
