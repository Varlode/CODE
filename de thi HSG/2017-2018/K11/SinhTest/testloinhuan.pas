uses math;
const
      fo = 'loinhuan12.inp';

var
      n : longint;

//--------------------------------------
procedure Process;
var i,j,a,m,dau: longint; ok:boolean;
begin
   randomize;
   n := 99960;
   m := random(20)+1;
   writeln(n-1+2*m);

   dau := 1;  ok := false;
   For i:=1 to n do
     Begin
       a := random(10000);
       if (a=0) and (ok=false) then
         begin
           for j:=1 to 2*m do
            begin
               write(dau*m,#32); dau := -dau;
            end;
           ok := true;
         end
       else write(a,#32);
     End;
end;
//--------------------------------------
BEGIN
  assign(output,fo); rewrite(output);

    Process;

  close(output);
END.
