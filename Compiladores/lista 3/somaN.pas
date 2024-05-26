program somaN(input, output);

var
    i, num: Integer;
    temp: Longint;
    result: longint;

begin
    readln(num);
    result:= 0;
    
    for i:= 1 to num do
    begin
        readln(temp);
        result := result + temp;
    end;

    writeln(result);
end.