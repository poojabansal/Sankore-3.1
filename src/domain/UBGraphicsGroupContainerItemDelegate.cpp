#include "UBGraphicsGroupContainerItemDelegate.h"

#include <QtGui>

#include "UBGraphicsScene.h"
#include "gui/UBResources.h"

#include "domain/UBGraphicsDelegateFrame.h"
#include "domain/UBGraphicsGroupContainerItem.h"

#include "board/UBBoardController.h"

#include "core/memcheck.h"

UBGraphicsGroupContainerItemDelegate::UBGraphicsGroupContainerItemDelegate(QGraphicsItem *pDelegated, QObject *parent) :
    UBGraphicsItemDelegate(pDelegated, parent, true, false, false), mDestroyGroupButton(0)

{
    //Wrapper function. Use it to set correct data() to QGraphicsItem as well
    setFlippable(false);
    setRotatable(false);
    setCanDuplicate(true);
}

UBGraphicsGroupContainerItem *UBGraphicsGroupContainerItemDelegate::delegated()
{
    return dynamic_cast<UBGraphicsGroupContainerItem*>(mDelegated);
}

void UBGraphicsGroupContainerItemDelegate::decorateMenu(QMenu *menu)
{
    mLockAction = menu->addAction(tr("Locked"), this, SLOT(lock(bool)));
    QIcon lockIcon;
    lockIcon.addPixmap(QPixmap(":/images/locked.svg"), QIcon::Normal, QIcon::On);
    lockIcon.addPixmap(QPixmap(":/images/unlocked.svg"), QIcon::Normal, QIcon::Off);
    mLockAction->setIcon(lockIcon);
    mLockAction->setCheckable(true);

    mShowOnDisplayAction = mMenu->addAction(tr("Visible on Extended Screen"), this, SLOT(showHide(bool)));
    mShowOnDisplayAction->setCheckable(true);

    QIcon showIcon;
    showIcon.addPixmap(QPixmap(":/images/eyeOpened.svg"), QIcon::Normal, QIcon::On);
    showIcon.addPixmap(QPixmap(":/images/eyeClosed.svg"), QIcon::Normal, QIcon::Off);
    mShowOnDisplayAction->setIcon(showIcon);
}

void UBGraphicsGroupContainerItemDelegate::buildButtons()
{
    UBGraphicsItemDelegate::buildButtons();
}

bool UBGraphicsGroupContainerItemDelegate::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    delegated()->deselectCurrentItem();
    return false;
}

bool UBGraphicsGroupContainerItemDelegate::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)

    return false;
}

bool UBGraphicsGroupContainerItemDelegate::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)

    return false;
}
