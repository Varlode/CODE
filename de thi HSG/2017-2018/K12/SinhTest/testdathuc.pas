const
      fo = 'Dathuc08.inp';
      MaxN = 50000;

var
     N,x: Longint;

//-------------------------------------
procedure taotest;
var i: longint;
begin
  randomize;
  x := random(10)+1;
  N := random(5)+1;
  writeln(x,#32,N);
  for i:= N downto 0 do write(random(100),#32);
end;
//--------------------------------------
BEGIN

    assign(Output,fo); rewrite(Output);

       taotest;

    Close(Output);
END.
