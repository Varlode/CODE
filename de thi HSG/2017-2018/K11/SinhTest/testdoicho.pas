uses math;
const maxN = 1000;

//-------------------------------
procedure sinhtest;
var m,n,i,j: longint;
begin
  randomize;
  n := 1000; m := random(1000)+1;
  writeln(m,#32,n);
  for i:=1 to m do
    begin
      for j:=1 to n do write(-i,#32);
      writeln;
    end;
end;
//----------------------------
BEGIN
  assign(output,'doicho08.inp'); rewrite(output);
   sinhtest;
  close(input); close(output);
END.
