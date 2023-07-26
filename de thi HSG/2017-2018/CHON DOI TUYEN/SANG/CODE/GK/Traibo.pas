// ma bai AGGRCOW
uses math;
const
      MaxN = 100000;    maxL = 1000000000;
      fi = 'traibo.inp';
      fo = 'traibo.out';


var  chuong: array[0..MaxN+1] of longint;
     free: array[0..MaxN+1] of boolean;
     N,M,T,dem,luui,d: longint;

function Kiemtra(d:longint): boolean;
var i,j: longint; kc: longint;
begin
  fillchar(free,sizeof(free),true);
  free[0] := false; free[n+1] := false;
  free[1] := false; luui := 1;
  dem := 1;
  for i:=1 to n do
   if (free[i]=false) then
     begin
       for j:=i+1 to n do
         if ((free[j]) and (chuong[j]-chuong[luui]>=d)) then
          begin
           free[j] := false;
           inc(dem);
           luui := j;
           break;
         end;

     end;

     if dem<m then exit(false) else exit(true);

end;
//----------------------------------
procedure xuli;
var i,j: longint; Dmax,Dmin,Smin: longint;
begin
   Dmax := chuong[n]-chuong[1];
   Dmin := 1;
   Smin := 0;
  while Dmin<=Dmax do  // tim Min bang cach chia nhi phan
    begin
      d := (Dmin + Dmax) div 2;
      if kiemtra(d) then
        begin
          Smin := d;
          Dmin := d + 1;
        end
      else Dmax := d - 1;
    end;

  writeln(Smin);
end;
//---------------------------------------
procedure DoiCho(var a,b:longint);
var tam: longint;
begin
  tam := a;
  a := b;
  b := tam;
end;
//-------------------------------------
Procedure QuickSort(L,H:longint);
Var i,j, Chot: longint;
Begin
  If L>=H then Exit;
  Chot := chuong[(L+H) div 2];
  i := L;
  j := H;
  Repeat
    While chuong[i] < Chot do inc(i);
    While chuong[j] > Chot do dec(j);
    If i<=j then
      Begin
        If i<j then DoiCho(chuong[i],chuong[j]);
        Inc(i); Dec(j);
      End;
  Until i>j;

  QuickSort(L,j);
  QuickSort(i,H);
End;
//-------------------------------------
procedure nhap;
 var i,j: longint;
 begin
    readln(T);
    for i:=1 to T do
     begin
      readln(n,m);
      for j:= 1 to n do readln(chuong[j]);
      QuickSort(1,n);
      xuli;
    end;
 end;
//------- -------------------------

BEGIN
assign(input,fi); reset(input); assign(output,fo); rewrite(output);

  nhap;

close(input); close(output);
END.

