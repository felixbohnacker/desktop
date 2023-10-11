/*
 * Copyright 2023 (c) Claudio Cambra <claudio.cambra@nextcloud.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 */

#pragma once

#include <QAbstractListModel>

#include "gui/macOS/fileprovideritemmetadata.h"

namespace OCC {

namespace Mac {

class FileProviderMaterialisedItemsModel : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(QVector<FileProviderItemMetadata> items READ items WRITE setItems NOTIFY itemsChanged)

public:
    enum Roles {
        IdentifierRole = Qt::UserRole + 1,
        ParentItemIdentifierRole,
        FilenameRole,
        TypeIdentifierRole,
        SymlinkTargetPathRole,
        UploadingErrorRole,
        DownloadingErrorRole,
        MostRecentEditorNameRole,
        OwnerNameRole,
        ContentModificationDateRole,
        CreationDateRole,
        LastUsedDateRole,
        ContentVersionRole,
        MetadataVersionRole,
        TagDataRole,
        CapabilitiesRole,
        FileSystemFlagsRole,
        ChildItemCountRole,
        TypeOsCodeRole,
        CreatorOsCodeRole,
        DocumentSizeRole,
        MostRecentVersionDownloadedRole,
        UploadingRole,
        UploadedRole,
        DownloadingRole,
        DownloadedRole,
        SharedRole,
        SharedByCurrentUserRole,
    };
    Q_ENUM(Roles)

    explicit FileProviderMaterialisedItemsModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = {}) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QVector<FileProviderItemMetadata> items() const;

signals:
    void itemsChanged();

public slots:
    void setItems(const QVector<FileProviderItemMetadata> &items);

private:
    QVector<FileProviderItemMetadata> _items;
};

} // namespace Mac

} // namespace OCC
