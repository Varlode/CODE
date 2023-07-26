const
      fi = 'Windows.inp';
      fo = 'Windows.out';
      MaxN = 100; MaxM = 100;

var
     x,y,u,v : array[1..MaxN] of Longint;
     ManHinh: array[0..MaxN-1,0..MaxN-1] of Longint;
     TrinhTu: array[1..MaxM] of longint;
     N,M,L: Longint;

procedure nhap;
var i: Longint;
begin
  Readln(N,M,L);
  For i:=1 to M do Readln(x[i],y[i],u[i],v[i]);
  For i:=1 to M do Read(TrinhTu[i]);

end;
//-------------------------------------
procedure Gannhan(k:Longint);
var i,j:Longint;
begin
  For i:=x[k] to u[k] do
    For j:=y[k] to v[k] do ManHinh[i,j] := k;
end;
//--------------------------------------
procedure xuli;
var i: longint;
begin
  for i:=1 to M do Gannhan(TrinhTu[i]);
end;
//--------------------------------------
Procedure Xuat;
var S,i,j: Longint;
Begin
  S := 0;
  For i:=x[L] to u[L] do
    For j:=y[L] to v[L] do
      if (ManHinh[i,j] = L) then inc(S);
  write(S);
End;

BEGIN

    assign(Input,fi); reset(Input);
    assign(Output,fo); rewrite(Output);

       Nhap;
       Xuli;
       Xuat;

    Close(Input);
    Close(Output);
END.
