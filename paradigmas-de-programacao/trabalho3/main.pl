:- use_module(library(clpfd)).

% pega informacoes do input, e separa entre as matrizes de chutes e areas
buildMatrix(File, Guesses, Areas) :-
    open(File, read, Stream),
    readLines(Stream, [], Lines),
    splitTupleMatrix(Lines, Guesses, Areas),
    close(Stream).

readLines(Stream, Acc, Lines) :-
    read(Stream, Line),
    (Line == end_of_file ->
            reverse(Acc, Lines);
            readLines(Stream, [Line|Acc], Lines)
    ).

% separa uma do tipo [a-b, ..., c-d] em duas matrizes [a, .., c] e [b, .., d]
splitTupleMatrix([], [], []).
splitTupleMatrix([Row|Rows], [FirstRow|FirstRows], [SecondRow|SecondRows]) :-
    splitTupleRow(Row, FirstRow, SecondRow),
    splitTupleMatrix(Rows, FirstRows, SecondRows).

splitTupleRow([], [], []).
splitTupleRow([A-B|Tuples], [A|FirstElements], [B|SecondElements]) :-
    splitTupleRow(Tuples, FirstElements, SecondElements).

% transforma duas matrizes em uma hashtable onde os elementos da primeira matriz
% indexam os da segunda, de forma que cada chave tenha uma lista como valor
matricesHash(Matrix1, Matrix2, HashTable) :-
    empty_assoc(EmptyHashTable),
    matricesHash(Matrix1, Matrix2, EmptyHashTable, HashTable).

matricesHash([], [], HashTable, HashTable).
matricesHash([Row1|Matrix1], [Row2|Matrix2], TempHashTable, HashTable) :-
    rowAssoc(Row1, Row2, TempHashTable, NewHashTable),
    matricesHash(Matrix1, Matrix2, NewHashTable, HashTable).

rowAssoc([], [], HashTable, HashTable).
rowAssoc([Key|Keys], [Value|Values], TempHashTable, HashTable) :-
    (get_assoc(Key, TempHashTable, ExistingList) ->
        append(ExistingList, [Value], NewList),
        put_assoc(Key, TempHashTable, NewList, NewHashTable); 
        put_assoc(Key, TempHashTable, [Value], NewHashTable)
    ),
    rowAssoc(Keys, Values, NewHashTable, HashTable).

% transforma uma matriz em uma lista
flatten([], []).
flatten([Row|Matrix], FlatList) :-
    flatten(Matrix, FlatListTail),
    append(Row, FlatListTail, FlatList).

% faz uma lista ter apenas elementos unicos
removeDuplicates([], []).
removeDuplicates([Head|Tail], UniqueList) :-
    member(Head, Tail),
    !,
    removeDuplicates(Tail, UniqueList).
removeDuplicates([Head|Tail], [Head|UniqueList]) :-
    removeDuplicates(Tail, UniqueList).

% testa se cada area esta de acordo com as regras do jogo, usando a lista de areas
% e uma hash table contendo os chutes de cada area
areaConstraint([], _) :- !.
areaConstraint([H|T], AreasHash) :-
    get_assoc(H, AreasHash, AreaList),

    % valor maximo na area eh tamanho da area
    length(AreaList, AreaLen),
    AreaList ins 1..AreaLen,

    % valores diferentes na area
    all_different(AreaList),

    areaConstraint(T, AreasHash).

% testa cada coluna de dois em dois elementos, verificando se eles sao diferentes
% e se, caso estejam na mesma area, o de cima eh maior que o de baixo
columnConstraint([], []).
columnConstraint([GColumn|GT], [AColumn|AT]) :-
    columnConstraintAux(GColumn, AColumn),
    columnConstraint(GT, AT).

columnConstraintAux([], []).
columnConstraintAux([_], [_]).
columnConstraintAux([G1, G2|GT], [A1, A2|AT]) :-
    (A1 == A2 ->
        G1 #> G2;
        G1 #\= G2
    ),
    columnConstraintAux([G2|GT], [A2|AT]).

% testa cada linha de dois em dois elementos, verificando se eles sao diferentes
rowConstraint([]).
rowConstraint([Row|T]) :-
    rowConstraintAux(Row),
    rowConstraint(T).

rowConstraintAux([]).
rowConstraintAux([_]).
rowConstraintAux([G1, G2|T]) :-
    G1 #\= G2,            
    rowConstraintAux([G2|T]).

% aplica cada constraint sobre a matriz de chutes
solve(Guesses, Areas) :-
    % constroi a hash de areas
    matricesHash(Areas, Guesses, Hash),
    % lista de areas
    flatten(Areas, AreasFlat), removeDuplicates(AreasFlat, AreasUnique),

    areaConstraint(AreasUnique, Hash),
    rowConstraint(Guesses),        
    transpose(Guesses, TrG),  transpose(Areas, TrA), 
    columnConstraint(TrG, TrA).

main(File) :-
    buildMatrix(File, Guesses, Areas),
    solve(Guesses, Areas),
    write(Guesses), nl,
    halt.
