#include <stdio.h>
#include <malloc.h>
#include <math.h>

struct distancia_tag{
	float d[1000][1000]; //Tipo float
}DISTANCIA;

struct tipo_de_ecoponto{
    int plastico[100];
    int vidrao[100];
    int papelao[100];
    int oleao[100];
}ecoponto, coordenada_x, coordenada_y;

int pedir_coordenada_x(){
    int x;
    printf("Introduza a coordenada x: ");
    scanf("%d", &x);
    return x;
} 

int pedir_coordenada_y(){
    int y;
    printf("Introduza a coordenada y: ");
    scanf("%d", &y);
    return y;
} 

void listar_ecopontos(){
    int i, sum=0, num_ecopontos, count;
    system("cls");
    printf("----Plastico----\n");
    for(i=0;i<(sizeof(ecoponto.plastico)/4);i++){
        if(ecoponto.plastico[i] != NULL){
            printf("Ecoponto: %d\n", i+1);
            printf("Quantidade ecoponto: %d\n", ecoponto.plastico[i]);
            printf("coordenada x: %d\ncoordenada y: %d\n", coordenada_x.plastico[i], coordenada_y.plastico[i]);
            sum = sum + ecoponto.plastico[i];
            count =count +1;
        }
    }   
    if(count != 0){
	    printf("Media de residuos nos ecopontos plastico: %d\n", sum/count);	
	}
    sum=0;
    count =0;
    printf("----Vidrao----\n");
    for(i=0;i<(sizeof(ecoponto.vidrao)/4);i++){
        if(ecoponto.vidrao[i] != NULL){
            printf("Ecoponto: %d\n", i+1);
            printf("Quantidade ecoponto: %d\n", ecoponto.vidrao[i]);
            printf("coordenada x: %d\ncoordenada y: %d\n", coordenada_x.vidrao[i], coordenada_y.vidrao[i]);
            sum = sum + ecoponto.vidrao[i];
            count =count +1;
        }
    }
    if(count != 0){
	    printf("Media de residuos nos ecopontos vidrao: %d\n", sum/count);	
	}
	sum=0;
    count =0;
    printf("----Oleao----\n");
    for(i=0;i<(sizeof(ecoponto.oleao)/4);i++){
        if(ecoponto.oleao[i] != NULL){
            printf("Ecoponto: %d\n", i+1);
            printf("Quantidade ecoponto: %d\n", ecoponto.oleao[i]);
            printf("coordenada x: %d\ncoordenada y: %d\n", coordenada_x.oleao[i], coordenada_y.oleao[i]);
            sum = sum + ecoponto.oleao[i];
            count =count +1;
        }
    }
    if(count != 0){
	    printf("Media de residuos nos ecopontos oleao: %d\n", sum/count);	
	}
    sum=0;
    count =0;
    printf("----Papelao----\n");
    for(i=0;i<(sizeof(ecoponto.papelao)/4);i++){
        if(ecoponto.papelao[i] != NULL){
            printf("Ecoponto: %d\n", i+1);
            printf("Quantidade ecoponto: %d\n", ecoponto.papelao[i]);
            printf("coordenada x: %d\ncoordenada y: %d\n", coordenada_x.papelao[i], coordenada_y.papelao[i]);
            sum=sum + ecoponto.papelao[i];
            count =count +1;
        }
    }
    if(count != 0){
	    printf("Media de residuos nos ecopontos papelao: %d\n", sum/count);	
	}
}

int conta_ecoponto(int option){ //funçao que conta o numero de ecopontos por tipo
	int i, size_ecoponto, res, count=0;
	
    switch (option){
    case 1://ecoponto plastico
        size_ecoponto = sizeof(ecoponto.plastico)/4;
	    for(i=0;i<size_ecoponto;i++){
		    res = ecoponto.plastico[i];
		    if(res != NULL){//contagem dos ecopontos
			    count = count + 1;
		    }
	    }
	    return count;
    break;
    case 2://ecoponto vidrao
        size_ecoponto = sizeof(ecoponto.vidrao)/4;
	    for(i=0;i<size_ecoponto;i++){
		    res = ecoponto.vidrao[i];
		    if(res != NULL){//contagem dos ecopontos
			    count = count + 1;
		    }
	    }
	    return count;
    break;  
    case 3://ecoponto oleao
        size_ecoponto = sizeof(ecoponto.oleao)/4;
	    for(i=0;i<size_ecoponto;i++){
		    res = ecoponto.oleao[i];
		    if(res != NULL){//contagem dos ecopontos
			    count = count + 1;
		    }
	    }
	    return count;        
    break;
    case 4://ecoponto papelao
        size_ecoponto = sizeof(ecoponto.papelao)/4; //Obter o numero de posições do array
	    for(i=0;i<size_ecoponto;i++){
		    res = ecoponto.papelao[i];
		    if(res != NULL){//contagem dos ecopontos
			    count = count + 1;
		    }
	    }
	    return count; 
    break;
    }
}

void insere_ecoponto_mapa(int x,int y){
    DISTANCIA.d[x][y]=1;
}

void delete_ecoponto_mapa(int id_ecoponto,int option){
    int x,y;

    if(option == 1){
        x=coordenada_x.plastico[id_ecoponto-1];
        y=coordenada_y.plastico[id_ecoponto-1];
        DISTANCIA.d[x][y] = 0;
    }else if(option == 2){
        x=coordenada_x.vidrao[id_ecoponto-1];
        y=coordenada_y.vidrao[id_ecoponto-1];
        DISTANCIA.d[x][y] = 0;
    }else if(option == 3){
        x=coordenada_x.oleao[id_ecoponto-1];
        y=coordenada_y.oleao[id_ecoponto-1];
        DISTANCIA.d[x][y] = 0;
    }else if(option == 4){
        x=coordenada_x.papelao[id_ecoponto-1];
        y=coordenada_y.papelao[id_ecoponto-1];
        DISTANCIA.d[x][y] = 0;
    }
    
}

void create_ecoponto(){
	int i, num_ecopontos, option, quantidade,x,y;
	
    system("cls");//limpa a consola
	printf("Escolha o tipo de ecoponto que deseja adicionar: \n");
	printf("1-Plastico\n");
	printf("2-Vidrao\n");
    printf("3-Oleao\n");
    printf("4-Papelao\n");
    printf("5-Sair\n");
    scanf("%d", &option);
    if(option == 1){
        printf("Qual a quantidade que deseja adicionar?\n");
        scanf("%d", &quantidade);
        if((quantidade < 0) || (quantidade > 100)){
        	printf("Quantidade Invalida");
        	create_ecoponto();
		}else{
        x=pedir_coordenada_x();
        y=pedir_coordenada_y();
        if(((x>=0) && (x<=1000)) && ((y<=1000) && (y>=0))){
            num_ecopontos=conta_ecoponto(option);
            coordenada_x.plastico[num_ecopontos]=x;
            coordenada_y.plastico[num_ecopontos]=y;
            ecoponto.plastico[num_ecopontos]=quantidade;
            insere_ecoponto_mapa(x,y);
        }else{
            printf("coordenadas erradas\n");
            create_ecoponto();
        }
    	}	
    }else if(option == 2){
        printf("Qual a quantidade que deseja adicionar?\n");
        scanf("%d", &quantidade);
        if((quantidade < 0) || (quantidade > 100)){
        	printf("Quantidade Invalida\n");
        	create_ecoponto();
		}else{        
        	x=pedir_coordenada_x();
        	y=pedir_coordenada_y();
        	if(((x>=0) && (x<=1000)) && ((y<=1000) && (y>=0))){
           		num_ecopontos=conta_ecoponto(option);
            	coordenada_x.vidrao[num_ecopontos]=x;
            	coordenada_y.vidrao[num_ecopontos]=y;
            	ecoponto.vidrao[num_ecopontos]=quantidade;
            insere_ecoponto_mapa(x,y);
        }else{
            printf("coordenadas erradas\n");
            create_ecoponto();
        }
        }
    }else if(option == 3){
        printf("Qual a quantidade que deseja adicionar?\n");
        scanf("%d", &quantidade);
        if((quantidade < 0) || (quantidade > 100)){
        	printf("Quantidade Invalida\n");
        	create_ecoponto();
		}else{
        	x=pedir_coordenada_x();
        	y=pedir_coordenada_y();
        	if(((x>=0) && (x<=1000)) && ((y<=1000) && (y>=0))){
            	num_ecopontos=conta_ecoponto(option);
            	coordenada_x.oleao[num_ecopontos]=x;
            	coordenada_y.oleao[num_ecopontos]=y;
            	ecoponto.oleao[num_ecopontos]=quantidade;
            	insere_ecoponto_mapa(x,y);
        	}else{
            	printf("coordenadas erradas\n");
            	create_ecoponto();
        	}
		}
    }else if(option == 4){
        printf("Qual a quantidade que deseja adicionar?\n");
        scanf("%d", &quantidade);
        if((quantidade < 0) || (quantidade > 100)){
        	printf("Quantidade Invalida\n");
        	create_ecoponto();
		}else{
        	x=pedir_coordenada_x();
        	y=pedir_coordenada_y();
        	if(((x>=0) && (x<=1000)) && ((y<=1000) && (y>=0))){
            	num_ecopontos=conta_ecoponto(option);
            	coordenada_x.papelao[num_ecopontos]=x;
            	coordenada_y.papelao[num_ecopontos]=y;
            	ecoponto.papelao[num_ecopontos]=quantidade;
            	insere_ecoponto_mapa(x,y);
        	}else{
            	printf("coordenadas erradas\n");
            	create_ecoponto();
        	}
		}
    }else if(option == 5){
        system("cls");
        main();
    }else{
        printf("Opcao Invalida\n");
        create_ecoponto();
    }
    system("cls");
}

void editar_ecopontos(){
    int i, option, id_ecoponto, nova_quantidade, cord_option,x ,y;

    system("cls");//limpa a consola
    listar_ecopontos();
    printf("\n");
    printf("Escolha o tipo de ecoponto que deseja editar: \n");
	printf("1-Plastico\n");
	printf("2-Vidrao\n");
    printf("3-Oleao\n");
    printf("4-Papelao\n");
    scanf("%d", &option);
    if(option == 1){
        printf("Insira o id do ecoponto: ");
        scanf("%d", &id_ecoponto);
        printf("Insira a nova quantidade: ");
        scanf("%d", &nova_quantidade);
        ecoponto.plastico[id_ecoponto-1]=nova_quantidade;
        printf("Deseja modificar as cordenadas?\n");
        printf("1-Sim\n");
        printf("2-Nao");
        scanf("%d", &cord_option);
        if(cord_option == 1){
            delete_ecoponto_mapa(id_ecoponto, 1);
            x=pedir_coordenada_x();
            y=pedir_coordenada_y();
            coordenada_x.plastico[id_ecoponto-1]=x;
            coordenada_y.plastico[id_ecoponto-1]=y;
        }
    }else if(option == 2){
        printf("Insira o id do ecoponto: ");
        scanf("%d", &id_ecoponto);
        printf("Insira a nova quantidade: ");
        scanf("%d", &nova_quantidade);
        ecoponto.vidrao[id_ecoponto-1]=nova_quantidade;
        printf("Deseja modificar as cordenadas?\n");
        printf("1-Sim\n");
        printf("2-Nao\n");
        scanf("%d", &cord_option);
        if(cord_option == 1){
            delete_ecoponto_mapa(id_ecoponto,2);
            x=pedir_coordenada_x();
            y=pedir_coordenada_y();
            coordenada_x.vidrao[id_ecoponto-1]=x;
            coordenada_y.vidrao[id_ecoponto-1]=y;
        }        
    }else if(option == 3){
        printf("Insira o id do ecoponto: ");
        scanf("%d", &id_ecoponto);
        printf("Insira a nova quantidade");
        scanf("%d", &nova_quantidade);
        ecoponto.oleao[id_ecoponto-1]=nova_quantidade;        
        printf("Deseja modificar as cordenadas?");
        printf("1-Sim");
        printf("2-Nao");
        scanf("%d", &cord_option);
        if(cord_option == 1){
            delete_ecoponto_mapa(id_ecoponto,3);
            x=pedir_coordenada_x();
            y=pedir_coordenada_y();
            coordenada_x.oleao[id_ecoponto-1]=x;
            coordenada_y.oleao[id_ecoponto-1]=y;
        }
    }else if(option == 4){
        printf("Insira o id do ecoponto: ");
        scanf("%d", &id_ecoponto);
        printf("Insira a nova quantidade");
        scanf("%d", &nova_quantidade);
        ecoponto.papelao[id_ecoponto-1]=nova_quantidade;
        printf("Deseja modificar as cordenadas?\n");
        printf("1-Sim\n");
        printf("2-Nao\n");
        scanf("%d", &cord_option);
        if(cord_option == 1){
            delete_ecoponto_mapa(id_ecoponto,4);
            x=pedir_coordenada_x();
            y=pedir_coordenada_y();
            coordenada_x.papelao[id_ecoponto-1]=x;
            coordenada_y.papelao[id_ecoponto-1]=y;
        }
    }else{
        printf("Opcao invalida");
        main();
    }
}

void remover_ecopontos(){
    int i, option, id_ecoponto, num_ecoponto;

    system("cls");//limpa a consola
    listar_ecopontos();
    printf("\n");
    printf("Escolha o tipo de ecoponto que deseja remover: \n");
	printf("1-Plastico\n");
	printf("2-Vidrao\n");
    printf("3-Oleao\n");
    printf("4-Papelao\n");
    scanf("%d", &option);
    if(option == 1){
        printf("Insira o id do ecoponto: ");
        scanf("%d", &id_ecoponto);
        num_ecoponto = conta_ecoponto(1);
        for(i=id_ecoponto-1;i<num_ecoponto;i++){
            ecoponto.plastico[i]=ecoponto.plastico[i+1];
            coordenada_x.plastico[i]=coordenada_x.plastico[i+1];
            coordenada_y.plastico[i]=coordenada_y.plastico[i+1];
            if((ecoponto.plastico[i] != NULL) && (ecoponto.plastico[i+1]==NULL)){
                ecoponto.plastico[i]=0;
            }
            if((coordenada_x.plastico[i] != NULL) && (coordenada_x.plastico[i+1]==NULL)){
                coordenada_x.plastico[i]=0;
            }  
            if((coordenada_y.plastico[i] != NULL) && (coordenada_y.plastico[i+1]==NULL)){
                coordenada_x.plastico[i]=0;
            }
            delete_ecoponto_mapa(id_ecoponto,option);              
        }        
    }else if(option == 2){
        printf("Insira o id do ecoponto: ");
        scanf("%d", &id_ecoponto);
        num_ecoponto = conta_ecoponto(2);
        for(i=id_ecoponto-1;i<num_ecoponto;i++){
            ecoponto.vidrao[i]=ecoponto.vidrao[i+1];
            coordenada_x.vidrao[i]=coordenada_x.vidrao[i+1];
            coordenada_y.vidrao[i]=coordenada_y.vidrao[i+1];
            if((ecoponto.vidrao[i] != NULL) && (ecoponto.vidrao[i+1]==NULL)){
                ecoponto.vidrao[i]=0;
            }
            if((coordenada_x.vidrao[i] != NULL) && (coordenada_x.vidrao[i+1]==NULL)){
                coordenada_x.vidrao[i]=0;
            }
            if((coordenada_y.vidrao[i] != NULL) && (coordenada_y.vidrao[i+1]==NULL)){
                coordenada_y.vidrao[i]=0;
            }
            delete_ecoponto_mapa(id_ecoponto,option);                        
        }
    }else if(option == 3){
        printf("Insira o id do ecoponto: ");
        scanf("%d", &id_ecoponto);
        num_ecoponto = conta_ecoponto(3);
        for(i=id_ecoponto-1;i<num_ecoponto;i++){
            ecoponto.oleao[i]=ecoponto.oleao[i+1];
            coordenada_x.oleao[i]=coordenada_x.oleao[i+1];
            coordenada_y.oleao[i]=coordenada_y.oleao[i+1];
            if((ecoponto.oleao[i] != NULL) && (ecoponto.oleao[i+1]==NULL)){
                ecoponto.oleao[i]=0;
            }
            if((coordenada_x.oleao[i] != NULL) && (coordenada_x.oleao[i+1]==NULL)){
                coordenada_x.oleao[i]=0;
            }
            if((coordenada_y.oleao[i] != NULL) && (coordenada_y.oleao[i+1]==NULL)){
                coordenada_y.oleao[i]=0;
            }
            delete_ecoponto_mapa(id_ecoponto,option);
        }
    }else if(option == 4){
        printf("Insira o id do ecoponto: ");
        scanf("%d", &id_ecoponto);
        num_ecoponto = conta_ecoponto(4);
        for(i=id_ecoponto-1;i<num_ecoponto;i++){
            ecoponto.papelao[i]=ecoponto.papelao[i+1];
            coordenada_x.papelao[i]=coordenada_x.papelao[i+1];
            coordenada_y.papelao[i]=coordenada_y.papelao[i+1];
            if((ecoponto.papelao[i] != NULL) && (ecoponto.papelao[i+1]==NULL)){
                ecoponto.papelao[i]=0;
            }
            if((coordenada_x.papelao[i] != NULL) && (coordenada_x.papelao[i+1]==NULL)){
                coordenada_x.papelao[i]=0;
            }
            if((coordenada_y.papelao[i] != NULL) && (coordenada_y.papelao[i+1]==NULL)){
                coordenada_y.papelao[i]=0;
            }
            delete_ecoponto_mapa(id_ecoponto,option);
        }
    }else{
        printf("Opcao Invalida");
        remover_ecopontos();
    } 
}

void exportar_ficheiro(){
    FILE *fd;
    int i, option, res1, res2, res3, res4;
    
    fd= fopen("lista.txt", "w");
    if(fd == NULL){
    	printf("Nao foi possivel criar ficheiro");
	}else{
		res1 = conta_ecoponto(1);
		fprintf(fd, "----Ecoponto plastico---- \n");
    	for(i=0;i<res1;i++){
    		fprintf(fd, "Id ecoponto plastico: %d\n", i + 1);
    		fprintf(fd, "Capacidade: %d\n", ecoponto.plastico[i]);
    		fprintf(fd, "coordenada X: %d\ncoordenada Y: %d\n", coordenada_x.plastico[i], coordenada_y.plastico[i]);
		}
		res2 = conta_ecoponto(2);
		fprintf(fd, "----Ecoponto Vidrao---- \n");
    	for(i=0;i<res2;i++){
    		fprintf(fd, "Id ecoponto vidrao: %d\n", i + 1);
    		fprintf(fd, "Capacidade: %d\n", ecoponto.vidrao[i]);
    		fprintf(fd, "coordenada X: %d\ncoordenada Y: %d\n", coordenada_x.vidrao[i], coordenada_y.vidrao[i]);
		}
        res3 = conta_ecoponto(3);
        fprintf(fd, "----Ecoponto Papelao---- \n");
    	for(i=0;i<res3;i++){
    		fprintf(fd, "Id ecoponto papelao: %d\n", i + 1);
    		fprintf(fd, "Capacidade: %d\n", ecoponto.papelao[i]);
    		fprintf(fd, "coordenada X: %d\ncoordenada Y: %d\n", coordenada_x.papelao[i], coordenada_y.papelao[i]);
		}
        res4 = conta_ecoponto(4);
		fprintf(fd, "----Ecoponto Oleao---- \n");
    	for(i=0;i<res4;i++){
    		fprintf(fd, "Id ecoponto oleao: %d\n", i + 1);
    		fprintf(fd, "Capacidade: %d\n", ecoponto.oleao[i]);
    		fprintf(fd, "coordenada X: %d\ncoordenada Y: %d\n", coordenada_x.oleao[i], coordenada_y.oleao[i]);
		}     
	}
	fclose(fd);
}

int num_total_ecoponto(){
	int i=0, j, k=0, contas[100];
    int array_x[100], array_y[100];
    float sum=0, distance;
    int x1,x2,y1,y2;

   system("cls");//limpa a consola
	for(i=0;i<1000;i++){
		for(j=0;j<1000;j++){
			if((DISTANCIA.d[i][j]) == 1){
                array_x[k]=j;
                array_y[k]=i;
                k = k + 1;
			}
		}
	}
	
	printf("Valor de K: %d", k);
    for(i=0;i<k;i++){
    	if(i == 0){
    		sum = sqrt(pow((array_x[i]-0),2)+pow((array_y[i]-0), 2));
		}else{
			x2=array_x[i];
			x1=array_x[i-1];
			y2=array_y[i];
			y1=array_y[i-1];
			distance = sqrt(pow((x2-x1),2)+pow((y2-y1), 2));
			sum = sum + distance;	
		}
    }
    printf("Distancia Percorrida = %f\n", sum);
}

int main(void){
    int i, option;

    printf("------MENU-----\n");
    printf("1-Adicionar ecopontos\n");
    printf("2-Listar ecopontos\n");
    printf("3-Remover ecopontos\n");
    printf("4-Exportar para ficheiro\n");
    printf("5-Calcular a distanicia\n");
    printf("6-Editar ecopontos\n");
    scanf("%d", &option);
    switch (option){
        case 1:
            create_ecoponto();
            main();
        break;
        case 2:
            listar_ecopontos();
            main();
        break;
        case 3:
            remover_ecopontos();
            main();
        break;
        case 4:
            exportar_ficheiro();
            main();
        break;
        case 5:
        	num_total_ecoponto();
            main();
        break;
        case 6:
            editar_ecopontos();
            main();
        break;
        case 7:
        break;
        default:
        break;
    }
    return 0;
}
