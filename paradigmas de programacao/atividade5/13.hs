apagarEnquanto :: (t -> Bool) -> [t] -> [t]
apagarEnquanto func [] = []
apagarEnquanto func (a:b) =
    if func a then
        apagarEnquanto func b
    else
        a:b

main = print (apagarEnquanto odd [1, 3, 4, 105, 102])
