#pragma once
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Cell
{
	char mine;
	int nums;
	int reveal;
	char flag;
}Cell;


const int size = 20;
Cell board[size][size];
int  numMines = 10;
bool game;
//Обнуляем массив
void clearBoard(void) {
	for( int i = 0; i < size; i++  ){
		for( int j = 0; j < size; j++ ) {
			board[i][j].nums = 0;
			board[i][j].reveal = 0;
			board[i][j].mine = ' ';
			board[i][j].flag = ' ';
		}
	}
}

//Генерим мины
void deployMines(void){
	int x = 0, y = 0, i = 0;

	for( i = 0; i < numMines; i++ ) {
		do {
			x = rand() % size;
			y = rand() % size;
		} while( board[x][y].mine == '*' );
		board[x][y].mine = '*';
	}
}

//Присваиваем индексы
void setBoard(void) {
	int i = 0, j = 0;
	for( i = 0; i < size; i++ ){
		for( j = 0; j < size; j++ ){
			if((board[i][j+1].mine == '*')&&(j<size-1)){board[i][j].nums++;}  //Справа
			if((board[i][j-1].mine == '*')&&(j>0)){board[i][j].nums++;}		  //Слева	

			if((board[i+1][j].mine == '*')&&(i<size-1)){board[i][j].nums++;}  //Сверху	
			if((board[i-1][j].mine == '*')&&(i>0)){board[i][j].nums++;}		  //Снизу

			//Диагонали
			if((board[i+1][j+1].mine == '*')&&(i<size-1)&&(j<size-1)){board[i][j].nums++;}
			if((board[i-1][j-1].mine == '*')&&(i>0)&&(j>0)){board[i][j].nums++;}
			if((board[i+1][j-1].mine == '*')&&(i<size-1)&&(j>0)){board[i][j].nums++;}
			if((board[i-1][j+1].mine == '*')&&(i>0)&&(j<size-1)){board[i][j].nums++;}
		}
	}
}

void showZeros(void){
	int i = 0, j = 0;
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			if((board[i][j].reveal == 1)&&(board[i][j].nums == 0)){
				if((board[i][j+1].nums < 2)&&(j<size-1)){board[i][j+1].reveal = 1;}
				if((board[i+1][j].nums < 2)&&(i<size-1)){board[i+1][j].reveal = 1;}
				if((board[i-1][j].nums < 2)&&(i>0)){board[i-1][j].reveal = 1;}
				if((board[i][j-1].nums < 2)&&(j>0)){board[i][j-1].reveal = 1;}
				//if((board[i+1][j+1].nums < 2)&&(i<size-1)&&(j<size-1)){board[i+1][j+1].reveal = 1;}
				//if((board[i-1][j-1].nums < 2)&&(i>0)&&(j>0)){board[i-1][j-1].reveal = 1;}
				//if((board[i-1][j+1].nums < 2)&&(i>0)&&(j<size-1)){board[i-1][j+1].reveal = 1;}
				//if((board[i+1][j-1].nums < 2)&&(i<size-1)&&(j>0)){board[i+1][j-1].reveal = 1;}
			}
		}
	}
	for(i = size-1; i > 0; i--)
	{
		for(j = size-1; j > 0; j--)
		{
			if((board[i][j].reveal == 1)&&(board[i][j].nums == 0))
			{
				if((board[i][j+1].nums < 2)&&(j<size-1)){board[i][j+1].reveal = 1;}
				if((board[i+1][j].nums < 2)&&(i<size-1)){board[i+1][j].reveal = 1;}
				if((board[i-1][j].nums < 2)&&(i>0)){board[i-1][j].reveal = 1;}
				if((board[i][j-1].nums < 2)&&(j>0)){board[i][j-1].reveal = 1;}
				//if((board[i+1][j+1].nums < 2)&&(i<size-1)&&(j<size-1)){board[i+1][j+1].reveal = 1;}
				//if((board[i-1][j-1].nums < 2)&&(i>0)&&(j>0)){board[i-1][j-1].reveal = 1;}
				//if((board[i-1][j+1].nums < 2)&&(i>0)&&(j<size-1)){board[i-1][j+1].reveal = 1;}
				//if((board[i+1][j-1].nums < 2)&&(i<size-1)&&(j>0)){board[i+1][j-1].reveal = 1;}
			}
		}
	}
}

namespace Mh2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	protected: 
	private: System::Windows::Forms::Button^  bStart;
	private: System::Windows::Forms::NumericUpDown^  nMines;
	private: System::Windows::Forms::Label^  label1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->bStart = (gcnew System::Windows::Forms::Button());
			this->nMines = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nMines))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->ColumnHeadersVisible = false;
			this->dataGridView1->Location = System::Drawing::Point(12, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(424, 403);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellMouseClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &Form1::dataGridView1_CellMouseClick);
			// 
			// bStart
			// 
			this->bStart->Location = System::Drawing::Point(445, 59);
			this->bStart->Name = L"bStart";
			this->bStart->Size = System::Drawing::Size(89, 36);
			this->bStart->TabIndex = 1;
			this->bStart->Text = L"Начать играть";
			this->bStart->UseVisualStyleBackColor = true;
			this->bStart->Click += gcnew System::EventHandler(this, &Form1::bStart_Click);
			// 
			// nMines
			// 
			this->nMines->Location = System::Drawing::Point(446, 33);
			this->nMines->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->nMines->Name = L"nMines";
			this->nMines->Size = System::Drawing::Size(88, 20);
			this->nMines->TabIndex = 2;
			this->nMines->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(445, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(89, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Количество мин";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(546, 428);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->nMines);
			this->Controls->Add(this->bStart);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nMines))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: void revealMines(void){
			for ( int i = 0; i < size; i++ ){
				for ( int j = 0; j < size; j++ ){
					if( board[i][j].mine == '*' ){
						dataGridView1[j , i]->Value = "X";
						dataGridView1[j , i]->Style->BackColor = System::Drawing::Color::Red;
					}
				}
			}
		}
		
		void revealZeros(void){
			showZeros();	//Открываем область
			showZeros();
			showZeros();
			for( int i = 0; i < size; i++ ){
				for( int j = 0; j < size; j++ ){
					if( ( board[i][j].reveal == 1 ) && ( dataGridView1[j , i]->Value != " " ) ){
						dataGridView1[j , i]->Value = Convert::ToInt32(board[i][j].nums);
						dataGridView1[j , i]->Style->BackColor = System::Drawing::Color::White;
						if(board[i][j].nums == 0){
							dataGridView1[j , i]->Value = " ";
						}
					}
				}
			}
		}

		//Создаём таблицу
		void createTab(void){
			numMines = Convert::ToInt32(nMines->Value);
			dataGridView1->RowCount = size;			 //Задаём количество строк
			dataGridView1->ColumnCount = size;			 //Задаем количество столбцов	

			//Заполняю таблицу решетками
			for (int i = 0; i < size; i++){
				for (int j = 0; j < size; j++){
					dataGridView1[i , j]->Value = Convert::ToString("#");
					dataGridView1[i , j]->Style->BackColor = System::Drawing::Color::LightGray; //Цвет ячеек
				}
			}
		}

			//Кнопка старт
	private: System::Void bStart_Click(System::Object^  sender, System::EventArgs^  e) {
				game = true;
				createTab();
				clearBoard();
				deployMines();
				setBoard();
			 }

			 //Клик по ячейке
	private: System::Void dataGridView1_CellMouseClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^  e) {
				 if ( game == true){	//Если мы еще не проиграли или не выйграли, то играем
					int i = Convert::ToInt32(e->RowIndex);
					int j = Convert::ToInt32(e->ColumnIndex);


					if( board[i][j].mine == '*' ) { 
						dataGridView1[j , i]->Value = Convert::ToString("X");
						MessageBox::Show("Вы проиграли :(");
						revealMines();
						game = false;
					} else {
						dataGridView1[j , i]->Value = Convert::ToString(board[i][j].nums);
						board[i][j].reveal = 1;
					}

					if( win() == true){
						MessageBox::Show("Поздравляю! Вы победили!!");
						game = false;
						for( int i = 0; i < size; i++ ){
							for( int j = 0; j < size; j++ ){
								if( board[i][j].mine == '*' ){
									dataGridView1[j , i]->Style->BackColor = System::Drawing::Color::Green;
								}
							}
						}
				    }
					revealZeros();
				 }
			 }

			 bool win(){
				int tmp = 0;
				for ( int i = 0; i < size; i++ ){
					for ( int j = 0; j < size; j++){ 
						if ( dataGridView1[i , j]->Value == "#" ){
							tmp++;
						}
					}
				}

				if ( tmp == numMines ) {
					return true;
				} else{
					return false;
				}
			}
};
}

