import java.awt.image.ReplicateScaleFilter;
import java.util.List;

import com.pengrad.telegrambot.TelegramBot;
import com.pengrad.telegrambot.TelegramBotAdapter;
import com.pengrad.telegrambot.model.Update;
import com.pengrad.telegrambot.model.request.ChatAction;
import com.pengrad.telegrambot.model.request.Keyboard;
import com.pengrad.telegrambot.model.request.KeyboardButton;
import com.pengrad.telegrambot.model.request.ReplyKeyboardMarkup;
import com.pengrad.telegrambot.request.GetUpdates;
import com.pengrad.telegrambot.request.SendChatAction;
import com.pengrad.telegrambot.request.SendMessage;
import com.pengrad.telegrambot.response.BaseResponse;
import com.pengrad.telegrambot.response.GetUpdatesResponse;
import com.pengrad.telegrambot.response.SendResponse;

public class Main {

	public static void main(String[] args){
		//Criação do objeto bot com as informações de acesso
		TelegramBot bot = TelegramBotAdapter.build("294229941:AAEicDXuH3ClLukXvMuN6iAIeqrS8x0w84g");
		
		//Criação do objeto que recebe as mensagens
		GetUpdatesResponse updatesResponse;
		
		//objeto responsável por gerenciar o envio de respostas
		SendResponse sendResponse;
		
		//objeto responsável por gerenciar o envio de ações do chat
		BaseResponse baseResponse;
		
		//controle de off-set, isto é, a partir deste ID será lido as mensagens pendentes na fila
		int m = 0;
		
		int conv = 0;//
		
		String [] t = {"Sim","Não"};
		ReplyKeyboardMarkup replykb = new ReplyKeyboardMarkup(t);
		
		//loop infinito pode ser alterado por algum timer de intervalo curto
		while(true){
			
			//executa comando no Telegram para obter as mensagens pendentes a partir de um off-set
			updatesResponse = bot.execute(new GetUpdates().limit(100).offset(m));
			
			//lista de mensagens
			List<Update> updates = updatesResponse.updates();
			
			//análise de cada ação da mensagem
			for (Update update : updates){
				
				//atualização do off-set
				m = update.updateId()+1;
				
				//envio de "Escrevendo" antes de enviar a resposta
				baseResponse = bot.execute(new SendChatAction(update.message().chat().id(), ChatAction.typing.name()));
				
				//Controlador da fase do diálogo dentro do DoomBot
				if (update.message().text().toUpperCase().equals("SIM"))
					conv = 1;
				else
					conv = conv;
				
				//Fase dos diálogos
				switch (conv){
				case 0:
					sendResponse = bot.execute(new SendMessage(update.message().chat().id(), "Olá, meu nome é Dooom Bot e estou programado para adivinhar qual personagem você está pensando!"));
					baseResponse = bot.execute(new SendChatAction(update.message().chat().id(), ChatAction.typing.name()));
					sendResponse = bot.execute(new SendMessage(update.message().chat().id(), "Vamos começar?"));
					baseResponse = bot.execute(new SendMessage(update.message().chat().id(),"").replyMarkup(replykb));
					
					break;
					
				case 1:
					sendResponse = bot.execute(new SendMessage(update.message().chat().id(), "Tudo bem!"));
					//METODO DE PERGUNTAS É CHAMADO AQUI
					/*if(!Perguntas.Fim()){ Metodo boleano
						sendResponse = bot.execute(new SendMessage(update.message().chat().id(), METODO QUE RETORNA A PERGUNTA COMO STRING AQUI));
					}*/

					break;
				case 2:
					//METODO DE RESPOSTA É CHAMADO AQUI
					//sendResponse = bot.execute(new SendMessage(update.message().chat().id(), "O Personagem no qual você está pensando é: " /*Metodo AQUI!*/));
					break;
				}
			}
		}
	}
}
