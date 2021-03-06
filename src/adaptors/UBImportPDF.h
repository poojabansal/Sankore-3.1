/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef UBIMPORTPDF_H_
#define UBIMPORTPDF_H_

#include <QtGui>
#include "UBImportAdaptor.h"

class UBDocumentProxy;

class UBImportPDF : public UBPageBasedImportAdaptor
{
    Q_OBJECT;

    public:
        UBImportPDF(QObject *parent = 0);
        virtual ~UBImportPDF();

        virtual QStringList supportedExtentions();
        virtual QString importFileFilter();

        virtual QList<UBGraphicsItem*> import(const QUuid& uuid, const QString& filePath);
        virtual void placeImportedItemToScene(UBGraphicsScene* scene, UBGraphicsItem* item);
        virtual const QString& folderToCopy();

	private:
		int dpi;
};

#endif /* UBIMPORTPDF_H_ */
