Dim objVOC : Set objVOC = CreateObject("SAPI.SpVoice")
Randomize

Function RandomWithinRange(min, max)
    RandomWithinRange = Int((max - min + 1) * Rnd() + min)
End Function

Function RandItemFromArray(arr)
    RandItemFromArray= arr(RandomWithinRange(LBound(arr), UBound(arr)))
End Function

Dim names
    names = Array("A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z")


objVOC.Speak (RandItemFromArray(names)+RandItemFromArray(names)+RandItemFromArray(names))