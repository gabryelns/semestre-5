program ajudeAparecido(input, output);

var
    i, num: Integer;
    temp: Longint;
    result: Longint;
    result_rodovalho: Longint;

begin
    readln(num);
    result:= 0;
    
    for i:= 1 to num do
    begin
        read(temp);
        result := result + temp;
    end;

    readln(result_rodovalho);

    if result = result_rodovalho then
        writeln('Acertou')
    else
        writeln('Errou');

end.