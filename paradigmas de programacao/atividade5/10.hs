filtrar :: (t -> Bool) -> [t] -> [t]
filtrar func lista = [a | a <- lista, func a]

main = print (filtrar odd [1..10])
