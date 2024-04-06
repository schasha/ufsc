alunos :: [(Int, String, Float)]
alunos = [(1, "Ana", 3.4), (2, "Bob", 6.7), (3, "Tom", 7.6)]

getNome :: (Int, String, Float) -> String
getNome (a,b,c) = b

getNota :: (Int, String, Float) -> Float
getNota (a,b,c) = c

getPrimeiroAluno :: [(Int, String, Float)] -> (Int, String, Float)
getPrimeiroAluno (a:_) = a

gerarPares :: (Eq t) => [t] -> [t] -> [(t,t)]
gerarPares l1 l2 = [(a,b) | a <- l1, b <- l2, a /= b]

aprovados :: [(Int, String, Float)] -> [String]
aprovados [] = []
aprovados lista = map getNome (filter (\(_, _, a) -> a >=6) lista)

aprovados2 :: [(Int, String, Float)] -> [String]
aprovados2 lista = [getNome aluno | aluno <- lista, getNota aluno >= 6]

main = do
    print (aprovados alunos)
    print (aprovados2 alunos)
    print (gerarPares alunos alunos)
