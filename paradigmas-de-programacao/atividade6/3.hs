data Ponto = Bidimencional Float Float | Tridimencional Float Float Float
distancia :: Ponto -> Ponto -> Float
distancia (Bidimencional x1 y1) (Bidimencional x2 y2) = ((y2-y1)**2 + (x2-x1)**2)**(1/2)
distancia (Tridimencional x1 y1 z1) (Tridimencional x2 y2 z2) = ((z2-z1)**2 + (y2-y1)**2 + (x2-x1)**2)**(1/2)

main = do
    print (distancia (Bidimencional 2 2)(Bidimencional 2 5))
    print (distancia (Tridimencional 2 2 3)(Tridimencional 2 3 1))
