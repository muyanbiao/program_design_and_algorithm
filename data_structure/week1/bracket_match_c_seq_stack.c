void BracketMatch(char *str) {
	SeqStack S; int i; char ch;
	InitStack(&S);
	for (i = 0; str[i] != '\0'; i++) {
		swich(str[i]) {
			case '(':case '[':case '{':
				Push(&S, str[i]); break;
			case ')':case ']':case '}':
				if (IsEmpty(&S)) {
					printf("\n右括号多余！");
					return;
				} else {
					GetTop(&S, &ch);
					if (Match(ch, str[i]))
						Pop(&S, &ch);
					else {
						printf("\n括号不匹配！");
						return;
					}
				}/*else*/
		}/*switch*/
	}/*for*/
	if (IsEmpty(&S))
		printf("\n括号匹配！");
	else printf("\n左括号多余");
}