uses math;
const
        fo='dentruong.inp';
        maxn=1000; maxL = 5;
var   n,m: longint;

procedure taotest;
var i,j,u,v,L,chieu:longint;
begin
        randomize;

       // n := maxn;

        n := random(maxn)+3;
        m := 2*n-3;;

        writeln(n,#32,m,#32);
        for i:=1 to (n-2) do
          begin
             u := i+1;
             v := i+2;
             chieu := random(2)+1;
            // chieu := 2;
             writeln(chieu,#32,i,#32,u,#32,random(maxL)+1);
             writeln(chieu,#32,i,#32,v,#32,random(maxL)+1);

          end;
        writeln(chieu,#32,u,#32,v,#32,random(maxL)+1);
end;

begin
        assign(output,fo);rewrite(output);
        taotest;
        close(output);
end.
