#include "Stage.h"
#include "resource.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Fbx.h"
#include "Engine/Camera.h"

void Stage::SetBlock(int _x, int _z, BLOCKTYPE _type)
{
    table_[_x][_z].type = _type;
}

void Stage::SetBlockHeight(int _x, int _z, int _height)
{
    table_[_x][_z].height = _height;
}

//コンストラクタ
Stage::Stage(GameObject* parent)
    :GameObject(parent, "Stage"), selectedAction(IDC_RADIO_UP)
{
    for (int i = 0; i < MODEL_NUM; i++)
    {
        hModel_[i] = -1;
    }
    for (int z = 0; z < ZSIZE; z++)
    {
        for (int x = 0; x < MODEL_NUM; x++)
        {
            SetBlock(x, z, DEFAULT);
        }
    }
}

//デストラクタ
Stage::~Stage()
{
}

//初期化
void Stage::Initialize()
{
    string modelname[] = {
        "BoxDefault.fbx",
        "BoxBrick.fbx",
        "BoxSand.fbx",
        "BoxWater.fbx",
        "BoxGrass.fbx"
    };
    string fname_base = "assets/";
    //モデルデータのロード
    for (int i = 0; i < MODEL_NUM; i++)
    {
        hModel_[i] = Model::Load(fname_base + modelname[i]);
        assert(hModel_[i] >= 0);
    }

    //tableにブロックのタイプをセットする
    for (int z = 0; z < ZSIZE; z++)
    {
        for (int x = 0; x < XSIZE; x++)
        {
            SetBlock(x, z, (BLOCKTYPE)(0));
            SetBlockHeight(x, z, 0);
        }
    }
}

//更新
void Stage::Update()
{
    if (!Input::IsMouseButtonDown(0))
    {
        return;
    }
    float w = (float)(Direct3D::scrWidth / 2.0f);
    float h = (float)(Direct3D::scrHeight / 2.0f);
    //Offsetx.yは0
    //minZ = 0 maxZ = 1

    XMMATRIX vp =
    {
        w, 0, 0, 0,
        0, -h, 0, 0,
        0, 0, 1, 0,
        w, h, 0, 1
    };
    //ビューポート
    XMMATRIX invVP = XMMatrixInverse(nullptr, vp);
    //プロジェクション変換
    XMMATRIX invProj = XMMatrixInverse(nullptr, Camera::GetProjectionMatrix());
    //ビュー変換
    XMMATRIX invView = XMMatrixInverse(nullptr, Camera::GetViewMatrix());
    XMFLOAT3 mousePosFront = Input::GetMousePosition();
    mousePosFront.z = 0.0f;
    XMFLOAT3 mousePosBack = Input::GetMousePosition();
    mousePosBack.z = 1.0f;
    //�@ mousePosFrontをベクトルに変換
    XMVECTOR vMouseFront = XMLoadFloat3(&mousePosFront);
    //�A �@にinvVP, invPrj, invViewをかける
    vMouseFront = XMVector3TransformCoord(vMouseFront, invVP * invProj * invView);
    //�B mousePosBackをベクトル変換
    XMVECTOR vMouseBack = XMLoadFloat3(&mousePosBack);
    //�C �BにinvVP, invPrj, invViewをかける
    vMouseBack = XMVector3TransformCoord(vMouseBack, invVP * invProj * invView);

    int bufX = -1, bufZ;
    float minDistance = 9999999;

    for (int x = 0; x < 15; x++)
    {
        for (int z = 0; z < 15; z++)
        {
            for (int y = 0; y < table_[x][z].height + 1; y++)
            {
                //�Dから�Cに向かってレイをうつ(とりあえずモデル番号はhModel_[0])
                RayCastData data;
                XMStoreFloat4(&data.start, vMouseFront);
                XMStoreFloat4(&data.dir,vMouseBack - vMouseFront);
                Transform trans;
                trans.position_.x = x;
                trans.position_.y = y;
                trans.position_.z = z;
                Model::SetTransform(hModel_[0], trans);

                Model::RayCast(hModel_[0], data);

                //�Eレイが当たったらブレークポイントで止める
                if (data.hit)
                {
                    if (minDistance > data.dist)
                    {
                        minDistance = data.dist;
                        bufX = x;
                        bufZ = z;
                    }
                }
            }
        }
    }
    if (bufX >= 0)
    {
        switch (mode_)
        {
        case 0:
            table_[bufX][bufZ].height++;
            break;
        case 1:
            if (table_[bufX][bufZ].height > 0)
            {
                table_[bufX][bufZ].height--;
            }
            break;
        case 2:
            table_[bufX][bufZ].type = select_;
            break;
        case 3:
            for (int x = 0; x < XSIZE; x++)
            {
                for (int z = 0; z < ZSIZE; z++)
                {
                    SetBlock(x, z, DEFAULT);
                    SetBlockHeight(x, z, 0);
                }
            }
            break;
        }
    }

}

//描画
void Stage::Draw()
{
    //Model::SetTransform(hModel_, transform_);
    //Model::Draw(hModel_);
    for (int x = 0; x < 15; x++)
    {
        for (int z = 0; z < 15; z++)
        {
            for (int y = 0; y < table_[x][z].height + 1; y++)
            {
                int type = table_[x][z].type;
                Transform trans;
                trans.position_.x = x;
                trans.position_.y = y;
                trans.position_.z = z;
                Model::SetTransform(hModel_[type], trans);
                Model::Draw(hModel_[type]);
            }
        }
    }
}

//開放
void Stage::Release()
{
}

//偽物のダイアログプロシージャ
BOOL Stage::DialogProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    //ダイアログができた
    case WM_INITDIALOG:
        //ラジオボタンの初期値
        SendMessage(GetDlgItem(hDlg, IDC_RADIO_UP), BM_SETCHECK, BST_CHECKED, 0);

        //コンボボックスの初期値
        SendMessage(GetDlgItem(hDlg, IDC_COMBO1), CB_ADDSTRING, 0, (LPARAM)"デフォルト");
        SendMessage(GetDlgItem(hDlg, IDC_COMBO1), CB_ADDSTRING, 0, (LPARAM)"レンガ");
        SendMessage(GetDlgItem(hDlg, IDC_COMBO1), CB_ADDSTRING, 0, (LPARAM)"草原");
        SendMessage(GetDlgItem(hDlg, IDC_COMBO1), CB_ADDSTRING, 0, (LPARAM)"砂地");
        SendMessage(GetDlgItem(hDlg, IDC_COMBO1), CB_ADDSTRING, 0, (LPARAM)"水");
        SendMessage(GetDlgItem(hDlg, IDC_COMBO1), CB_SETCURSEL, 0, 0);

        return TRUE;

    case WM_COMMAND:
        // ボタンのクリックイベント処理
        switch (LOWORD(wParam)) 
        {
        case IDC_RADIO_UP:
            mode_ = 0;
            return TRUE;

        case IDC_RADIO_DOWN:
            mode_ = 1;
            return TRUE;

        case IDC_RADIO_CHANGE:
            mode_ = 2;
            return TRUE;

        case IDC_COMBO1:
            /*ラジオボタンがクリックされたら、選択アクションを更新
            selectedAction = LOWORD(wParam);
            break;*/
            select_ = (int)SendMessage(GetDlgItem(hDlg, IDC_COMBO1), CB_GETCURSEL, 0, 0);
            return TRUE;

        case IDC_RADIO_RESTORE:
            mode_ = 3;
            return TRUE;
        }
        return FALSE;
    }
    return FALSE;
}

std::string Stage::StageData()
{
    std::string stageData;

    int count = 0;

    for (int x = 0; x < XSIZE; x++)
    {
        for (int z = 0; z < ZSIZE; z++)
        {
            stageData += std::to_string(table_[x][z].type) + ",";
            stageData += std::to_string(table_[x][z].height) + "  ";

            count++;

            if (count >= 15)
            {
                stageData += "\n";
                count = 0;
            }
        }
    }
    return stageData;
}

void Stage::Save()
{
    char fileName[MAX_PATH] = "無題.map";        //ファイル名を入れる変数

    //「ファイルを保存」ダイアログの設定
    OPENFILENAME ofn;                            //名前をつけて保存ダイアログの設定用構造体
    ZeroMemory(&ofn, sizeof(ofn));               //構造体初期化
    ofn.lStructSize = sizeof(OPENFILENAME);      //構造体のサイズ
    ofn.lpstrFilter = TEXT("マップデータ(*.map)\0*.map\0")  //─┬ファイルの種類
        TEXT("すべてのファイル(*. *)\0*. *\0\0");           //─┘
    ofn.lpstrFile = fileName;                    //ファイル名
    ofn.nMaxFile = MAX_PATH;                     //パスの最大文字数
    ofn.Flags = OFN_OVERWRITEPROMPT;             //フラグ（同名ファイルが存在したら上書き確認）
    ofn.lpstrDefExt = "map";                     //デフォルト拡張子

    //「ファイルを保存」ダイアログ
    BOOL selFile;
    selFile = GetSaveFileName(&ofn);

    //キャンセルしたら中断
    if (selFile == FALSE) return;

    //セーブのルーチン
    HANDLE hFile;
    hFile = CreateFile(
        fileName,               //ファイル名
        GENERIC_WRITE,          //アクセスモード（書き込み用）
        0,                      //共有（なし）
        NULL,                   //セキュリティ属性（継承しない）
        CREATE_ALWAYS,          //作成方法
        FILE_ATTRIBUTE_NORMAL,  //属性とフラグ（設定なし）
        NULL);                  //拡張属性（なし）

    std::string data = StageData(); // ステージ情報を文字列として取得

    DWORD dwBytes = 0;                //書き込み位置
    WriteFile(
        hFile,                        //ファイルハンドル
        data.c_str(),                 //保存するデータ（文字列）
        (DWORD)strlen(data.c_str()),  //書き込む文字数
        &dwBytes,                     //書き込んだサイズを入れる変数
        NULL);                        //オーバーラップド構造体（今回は使わない）

    CloseHandle(hFile);
}

void Stage::Load()
{
    char fileName[MAX_PATH] = {}; // ファイル名のバッファ

    // 「ファイルを開く」ダイアログを設定
    OPENFILENAME ofn;
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(OPENFILENAME);
    ofn.lpstrFilter = TEXT("マップデータ(*.map)\0*.map\0")
        TEXT("すべてのファイル(*.*)\0*.*\0\0");
    ofn.lpstrFile = fileName;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_FILEMUSTEXIST; // ロードの場合、ファイルは存在している必要がある
    //ofn.lpstrDefExt = "map";

    // 「ファイルを開く」ダイアログを表示
    BOOL selFile;
    selFile = GetOpenFileName(&ofn);

    // キャンセルされたか、ファイルが選択されなかった場合
    if (selFile == FALSE) return;
 
    HANDLE hFile;        //ファイルのハンドル
    hFile = CreateFile(
        fileName,                 //ファイル名
        GENERIC_READ,           //アクセスモード（書き込み用）
        0,                      //共有（なし）
        NULL,                   //セキュリティ属性（継承しない）
        OPEN_EXISTING,           //作成方法
        FILE_ATTRIBUTE_NORMAL,  //属性とフラグ（設定なし）
        NULL); //拡張属性（なし）

    //ファイルのサイズを取得
    DWORD fileSize = GetFileSize(hFile, NULL);

    //ファイルのサイズ分メモリを確保
    char* data;
    data = new char[fileSize];

    DWORD dwBytes = 0; //読み込み位置
    ReadFile(
        hFile,     //ファイルハンドル
        data,      //データを入れる変数
        (DWORD)fileSize,  //読み込むサイズ
        &dwBytes,  //読み込んだサイズ
        NULL);     //オーバーラップド構造体（今回は使わない）

    CloseHandle(hFile);
}