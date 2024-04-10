type Nome = String
type Disciplina = String
type Nota = Float
type Aluno = (Nome, Disciplina, Nota, Nota, Nota)

aluno :: Int -> Aluno
aluno 1 = ("Davi", "ORG", 3, 9.5, 6)
aluno 2 = ("Artur", "ORG", 6, 6, 6)

getNome :: Aluno -> String
getNome (n, _, _, _, _) = n

getNotas :: Aluno -> [Float]
getNotas (_, _, a, b, c) = [a, b, c]

media :: [Float] -> Float
media lst = sum lst / fromIntegral (length lst)

getMediaId :: Int -> Float
getMediaId x = media (getNotas (aluno x))

main = do
    print (getNome (aluno 1))
    print (getMediaId 1)
