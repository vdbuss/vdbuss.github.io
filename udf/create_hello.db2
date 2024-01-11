create function hello () returns varchar(80)
  external name 'hellib!hello'
  language C
  parameter style SQL
;
