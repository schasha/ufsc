mapear :: (t -> y) -> [t] -> [y]
mapear func lista = [func a | a <- lista]

main = print (mapear abs [-1..10])
