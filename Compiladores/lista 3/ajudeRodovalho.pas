program ajuder(input, output);

var
    num1: Longint;
    num2: Longint;
    num3: Longint;
    result_rodovalho: longint;
    result: longint;

begin
    read(num1);
    read(num2);
    read(num3);

    readln(result_rodovalho);

    result := num1 + num2 + num3;

        if result = result_rodovalho then
            writeln('Acertou')
        else
            writeln('Errou')

end.