#ifndef GUIDEWARETRACKINGWINDOW_H
#define GUIDEWARETRACKINGWINDOW_H

#include <Patient.h>
#include <SystemDispatcher.h>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include <QPixmap>
#include <QPalette>
#include <QBrush>
#include <QBitmap>
#include <QVTKWidget.h>
#include <QImage>
#include <QMessageBox>
#include <QLineEdit>
#include <QTimer>
#include <QDirIterator>
#include <QColor>
#include <QByteArray>

#include <vtkBMPReader.h>
#include <vtkOBJReader.h>
#include <vtkSmartPointer.h>
#include <vtkImageViewer2.h>
#include <vtkDICOMImageReader.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkImageCanvasSource2D.h>
#include <vtkSphereSource.h>
#include <vtkSmartPointer.h>
#include <vtkPolyDataMapper.h>
#include <vtkImageMapper.h>
#include <Patient.h>
#include <vtkPNGReader.h>
#include <BidimensionnelImage.h>
#include <vtkSmartPointer.h>
#include <vtkImageReader2Factory.h>
#include <vtkImageReader2.h>
#include <vtkImageData.h>
#include <vtkImageMapper3D.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkInteractorStyleImage.h>
#include <vtkRenderer.h>
#include <vtkImageActor.h>
#include <vtkFixedPointVolumeRayCastMapper.h>
#include <vtkImageLuminance.h>
#include <vtkImageFlip.h>
#include <vtkActor2D.h>
#include <vtkImageMagnify.h>


/**
 * @brief The GuidewareTrackingWindow class
 */
class GuidewareTrackingWindow : public QWidget
{
    Q_OBJECT

public:
    void setWorkSpaceColor(QString workspaceColor);
    void initVariable();
    void displayWindow();
    void constructionIHM();
    void setConnections();
    void drawBackground();
    void displayImage(vtkActor2D* act);
    void setPatientHandling(Patient *patientHandling);
    void update();

    QString getCurrentNormalFileName(long long index);
    QString getCurrentReconstructFileName(long long index);
    vtkActor2D* readRawFile(const QString &file);


private:

    vtkSmartPointer<vtkRenderer> renderer;
    vtkSmartPointer<vtkRenderWindow> renderWindow;
    vtkSmartPointer<vtkRenderer> mainRenderer;
    vtkSmartPointer<vtkImageActor> ctImageActor;
    //vtkSmartPointer<vtkCamera> camera;
    vtkSmartPointer<vtkImageData> imageData;
    vtkSmartPointer<vtkInteractorStyleImage > interactorStyleImage;
    vtkSmartPointer<vtkImageMapper> mapper;


    vtkImageReader *imageReader;

    long long currentNormalIndex;
    long long currentReconstructIndex;
    QDir currentWorkDir;

    QString collaborativeState;
    QString collaborativeName;
    QString collaborativeType;
    QString collaborativePath;

    QString currentFilePath;
    QString configuratonFilePath;

    QString globalWorkSpaceColor;

    int workspaceRed;
    int workspaceGreen;
    int workspaceBlue;

    QTimer *displayTaskTimer;

    int x;
    int y;
    int width;
    int height;
    Patient* patientHandling;
    SystemDispatcher* systemDispatcher;

    QFont *caracterStyle;
    QString windowStyleSheet;

    QPixmap *pixmap;

    QGridLayout* guidewareTrackingLayout;
    QGridLayout* vtkDisplayBoardLayout;
    QVBoxLayout* guideControlBoardLayout;
    QGridLayout* surgeryInformationLayout;
    QGridLayout* controlButtonAreaLayout;

    QPushButton* closeButton;
    QPushButton* playButton;
    QPushButton* noVolumeButton;
    QPushButton* screenShotButton;
    QPushButton* zoomInButton;
    QPushButton* zoomOutButton;
    QPushButton* measureButton;
    QPushButton* settingButton;
    QPushButton* recordButton;
    QPushButton* resetButton;
    QPushButton* fullButton;
    QPushButton* undoButton;
    QPushButton* leftTurnButton;
    QPushButton* rightTurnButton;
    QPushButton* showVesselButton;
    QPushButton* showGuidewireLocation;

    QWidget* vtkDisplayBar;
    QWidget* guideControlBoard;
    QWidget* vtkDisplayBoard;
    QWidget* realTimeDisplay;
    QWidget* lastFrameWidget;
    QWidget* guidewareTrackingDisplay;
    QWidget* CarmStructureWidget;
    QWidget* surgeryInformation;
    QWidget* controlButtonArea;
    QWidget* unknownArea;

    QVTKWidget* guidewareTrackingDisplayWidget;
    QVTKWidget* CarmStructureDisplay;

    QHBoxLayout* realTimeDisplayLayout;
    QHBoxLayout* lastFrameLayout;
    QHBoxLayout* guidewareTrackingDisplayLayout;
    QHBoxLayout* CarmStructureLayout;
    QHBoxLayout* r_layout;

    QLabel* nameBar;
    QLabel* surgeryID;
    QLabel* patientName;
    QLabel* surgeryDate;

    QLineEdit* surgeryIDLineEdit;
    QLineEdit* patientNameLineEdit;
    QLineEdit* surgeryDateLineEdit;


public slots:
    void closeSystem();
    void screenShot();
    void updateLastFrame();
    void changeStateToReconstruct();

public:
    explicit GuidewareTrackingWindow(QRect rect,
                                     SystemDispatcher* systemDispatcher,
                                     QString globalWorkSpaceColor,
                                     QString configuratonFilePath);
    ~GuidewareTrackingWindow();
};

#endif // GUIDEWARETRACKINGWINDOW_H
